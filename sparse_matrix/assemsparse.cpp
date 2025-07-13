#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

//buiding triplet
struct Triplet
{
    int row;
    int col;
    double value;
};

// Comparator for sorting triplets by row and then column
bool compareTriplet(const Triplet& a,const Triplet& b)
{
    if(a.row!=b.row)
    {
        return a.row<b.row;
    }
    return a.col<b.col;
}

class SparseMatrix
{

public:
    int numNodes;
    int SystemDOF;
    int totalDOF;

    vector<Triplet> globalTriplets;

    //constructor
    SparseMatrix(int nodes,int dofPerNode)
    {
        numNodes=nodes;
        SystemDOF=dofPerNode;
        totalDOF=numNodes*SystemDOF;
    }

    void assembleElement(const vector<int>& elemNodes,const vector<vector<double>>& ke)
    {
        vector<int> elemGlobalDOFs;

        //build global dof mapping
        for(int n:elemNodes)
        {
            for(int d=0;d<SystemDOF;d++)
            {
                elemGlobalDOFs.push_back(n*SystemDOF+d);
            }
        }

        //assemble to global triplet
        int nDOF=elemGlobalDOFs.size();
        for(int i=0;i<nDOF;i++)
        {
            for(int j=0;j<nDOF;j++)
            {
                if(ke[i][j]!=0)
                {
                    Triplet t;
                    t.row=elemGlobalDOFs[i];
                    t.col=elemGlobalDOFs[j];
                    t.value=ke[i][j];
                    globalTriplets.push_back(t);
                }
            }
        }
    }

    //Merge duplicates and convert to CSR
    void convertToCSR(vector<double>& values,vector<int>& colIndices,vector<int>& rowPtr)
    {
        sort(globalTriplets.begin(),globalTriplets.end(),compareTriplet);

        values.clear();
        colIndices.clear();
        rowPtr.clear();

        int prevRow=0;
        int nnz=0;

        //resizing , For n rows, rowPtr always needs n + 1 entries
        rowPtr.resize(totalDOF + 1, 0);  // 

        for(size_t i=0;i<globalTriplets.size();i++)
        {
            if(i>0 && globalTriplets[i].row==globalTriplets[i-1].row && globalTriplets[i].col==globalTriplets[i-1].col)
            {
                values.back()+=globalTriplets[i].value;
            }
            else
            {
                while(prevRow<globalTriplets[i].row)
                {
                    rowPtr[++prevRow]=nnz;
                }
                values.push_back(globalTriplets[i].value);
                colIndices.push_back(globalTriplets[i].col);
                nnz++;
            }
        }

        //finalize remaining rows
        while(prevRow<totalDOF)
        {
            rowPtr[++prevRow]=nnz;
        }

    }

    vector<double> sparseMultiplyVector(vector<double> x,vector<double>& values,vector<int>& colIndices,vector<int>& rowPtr)
    {
        vector<double> y(totalDOF,0.0);
        if(x.size() != totalDOF)
        {   
            cout << "\n=== y = A * x ===\n";
            cout<<"Rows of matrix and size of vector not matching"<<endl;
            return {0.0};
        }
        else
        {
            for (int i = 0; i < totalDOF; ++i)
            {
                for (int j = rowPtr[i]; j < rowPtr[i + 1]; ++j)
                {
                    y[i] += values[j] * x[colIndices[j]];
                }
            }

            return y;
        }
    }

    vector<double> solverJacobi(vector<double>& b, const vector<double>& values,const vector<int>& colIndices,
                            const vector<int>& rowPtr,double tol,int maxIter)
    {
        vector<double> x(totalDOF, 0.0); 
        vector<double> x_new(totalDOF, 0.0);
        double error = 1.0;
        int iter = 0;

        while (error > tol && iter < maxIter)
        {   
    
            for (int row = 0; row < totalDOF; row++)
            {
                double sum = 0.0;   // Reset per row
                double diag = 0.0;

                for (int idx = rowPtr[row]; idx < rowPtr[row + 1]; idx++)
                {
                    int col = colIndices[idx];
                    if (col == row)
                        diag = values[idx];
                    else
                        sum += values[idx] * x[col];
                }

                if (diag != 0)
                {
                    x_new[row] = (b[row] - sum) / diag;
                }
                else
                {
                    cout << "========= Warning: Diagonal is zero at row " << row << " =============\n";
                    x_new[row] = 0;
                }
            }

            // compute L2 norm
            error = 0.0;
            for (int row = 0; row < totalDOF; row++)
            {
                error += (x_new[row] - x[row]) * (x_new[row] - x[row]);
            }
            error = sqrt(error);

            x = x_new;
            iter++;
        }

        if (iter == maxIter)
            cout << "Jacobi did not converge after " << maxIter << " Iterations.\n";
        else
            cout << "Jacobi converged in " << iter << " Iterations.\n";

        return x;
    }

    vector<double> solverGaussSidel(vector<double>& b, const vector<double>& values,const vector<int>& colIndices,
                            const vector<int>& rowPtr,double tol,int maxIter)
    {
        vector<double> x(totalDOF, 0.0); 
        double error = 1.0;
        int iter = 0;

        while (error > tol && iter < maxIter)
        {   
            error=0.0;
    
            for (int row = 0; row < totalDOF; row++)
            {
                double sum = 0.0;   // Reset per row
                double diag = 0.0;

                for (int idx = rowPtr[row]; idx < rowPtr[row + 1]; idx++)
                {
                    int col = colIndices[idx];
                    if (col == row)
                        diag = values[idx];
                    else
                        sum += values[idx] * x[col];
                }

                double x_old=x[row];
                if (diag != 0)
                {
                    x[row] = (b[row] - sum) / diag;
                }
                else
                {
                    cout << "========= Warning: Diagonal is zero at row " << row << " =============\n";
                    x[row] = 0;
                }

                error += (x[row] - x_old) * (x[row] - x_old);
            }
            error = sqrt(error);
            iter++;
        }

        if (iter == maxIter)
            cout << "Gauss-Seidel did not converge after " << maxIter << " Iterations.\n";
        else
            cout << "Gauss-Seidel converged in " << iter << " Iterations.\n";

        return x;
    }

    vector<double> solverCG(vector<double>& b, const vector<double>& values,const vector<int>& colIndices,
                            const vector<int>& rowPtr,double tol,int maxIter)
    {
        vector<double> x(totalDOF,0.0);
        vector<double> r=b;
        vector<double> p=r;
        vector<double> Ap(totalDOF,0.0);

        double rs_old=0.0;
        for(int i=0;i<totalDOF;i++)
        {
            rs_old+=r[i]*r[i];
        }

        for(int iter=0;iter<maxIter;iter++)
        {
            fill(Ap.begin(),Ap.end(),0.0);
            for(int i=0;i<totalDOF;i++)
            {
                for(int j=rowPtr[i];j<rowPtr[i+1];j++)
                {
                    Ap[i]+=values[j]*p[colIndices[j]];
                }
            }

            double alpha_num=rs_old;
            double alpha_den=0.0;
            for(int i=0;i<totalDOF;i++)
            {
                alpha_den+=p[i]*Ap[i];
            }

            // step size
            double alpha=alpha_num/alpha_den;

            // solution update x
            for(int i=0;i<totalDOF;i++)
            {
                x[i]+=alpha*p[i];
            }

            // update r
            for(int i=0;i<totalDOF;i++)
            {
                r[i]-=alpha*Ap[i];
            }

            //new r calculation
            double rs_new=0.0;
            for(int i=0;i<totalDOF;i++)
            {
                rs_new+=r[i]*r[i];
            }

            if(sqrt(rs_new)<tol)
            {
                cout<<"CG Converged in "<<iter+1<<" iterations.\n";
                break;
            }

            //calculationg direction
            double beta=rs_new/rs_old;
            for(int i=0;i<totalDOF;i++)
            {
                p[i]=r[i]+beta*p[i];
            }

            rs_old=rs_new;

        }

        return x;
    }

    vector<double> solverPCG_Jacobi(vector<double>& b, const vector<double>& values,const vector<int>& colIndices,
                            const vector<int>& rowPtr,double tol,int maxIter)
    {
        vector<double> x(totalDOF,0.0);
        vector<double> r=b; // itnitial r
        vector<double> z(totalDOF,0.0);
        vector<double> p(totalDOF,0.0);
        vector<double> Ap(totalDOF,0.0);

        // preconditional calculation:- Jacobi (iverse of the diagonal)
        vector<double> M_inv(totalDOF,1.0);
        for(int row=0;row<totalDOF;row++)
        {
            for(int idx=rowPtr[row];idx<rowPtr[row+1];idx++)
            {
                if(colIndices[idx]==row)
                {
                    if(values[idx]!=0.0)
                    {
                        M_inv[row]=1.0/values[idx];
                    }
                }
            }
        }

        // intialize z=M_inv*r
        for(int i=0;i<totalDOF;i++)
        {
            z[i]=M_inv[i]*r[i];
        }
        p=z;

        double rz_old=0.0;
        for(int i=0;i<totalDOF;i++)
        {
            rz_old+=z[i]*r[i];
        }

        for(int iter=0;iter<maxIter;iter++)
        {
            fill(Ap.begin(),Ap.end(),0.0);
            for(int i=0;i<totalDOF;i++)
            {   
                for(int j=rowPtr[i];j<rowPtr[i+1];j++)
                {
                    Ap[i]+=values[j]*p[colIndices[j]];
                }
            }

            double alpha=rz_old;
            double denom=0.0;
            for(int i=0;i<totalDOF;i++)
            {
                denom+=p[i]*Ap[i];
            }

            if (fabs(denom) < 1e-14) 
            {
                cout << "Denominator near zero, breaking to avoid instability.\n";
                break;
            }

            // step size
            alpha/=denom;

            // solution update x
            for(int i=0;i<totalDOF;i++)
            {
                x[i]+=alpha*p[i];
            }

            // update r
            for(int i=0;i<totalDOF;i++)
            {
                r[i]-=alpha*Ap[i];
            }

            //new r calculation
            double norm_r=0.0;
            for(double v:r) norm_r+=v*v;

            if(norm_r < tol*tol)
            {
                cout<<"PCG with Jacobi converged in "<<iter+1<<" iterations.\n";
                break;
            }

            for(int i=0;i<totalDOF;i++)
            {
                z[i]=M_inv[i]*r[i];

            }

            double rz_new=0.0;
            for (int i = 0; i < totalDOF; ++i)
            {
                rz_new += r[i] * z[i];
            }

            //calculationg direction
            double beta=rz_new/rz_old;
            for(int i=0;i<totalDOF;i++)
            {
                p[i]=z[i]+beta*p[i];
            }

            rz_old=rz_new;

        }

        return x;
    }


    void printTriplets()
    {
        cout << "\n=== Assembled Global Triplets (non-zero only) ===" << endl;
        for (const auto& t : globalTriplets)
        {
            cout << "(" << t.row << "," << t.col << ") = " << t.value << endl;
        }
        cout<<endl<<endl;
    }

    // Print CSR arrays
    void printCSR(const vector<double>& values, const vector<int>& colIndices, const vector<int>& rowPtr)
    {
        cout << "\n=== CSR Format ===" << endl;
        cout << "Values: ";
        for (double v : values) cout << v << " ";
        cout << "\nCol indices: ";
        for (int c : colIndices) cout << c << " ";
        cout << "\nRow pointer: ";
        for (int r : rowPtr) cout << r << " ";
        cout << endl;
    }

};

int main()
{
    int numNodes = 5;
    int systemDOF = 1;

    SparseMatrix smat(numNodes, systemDOF);

    vector<vector<double>> ke = {
        {4, -1, 0, 0, 0},
        {-1, 4, -1, 0, 0},
        {0, -1, 4, -1, 0},
        {0, 0, -1, 4, -1},
        {0, 0, 0, -1, 3}
    };


    vector<int> elemNodes = {0, 1, 2, 3, 4};
    smat.assembleElement(elemNodes, ke);

    vector<double> values;
    vector<int> colIndices;
    vector<int> rowPtr;

    smat.convertToCSR(values, colIndices, rowPtr);

    // RHS vector b
    vector<double> b = {15.0, 117.0, 10.0, 12.0, 33.0};

    vector<double> x_jacobi = smat.solverJacobi(b, values, colIndices, rowPtr, 1e-6, 1000);
    vector<double> x_gs = smat.solverGaussSidel(b, values, colIndices, rowPtr, 1e-6, 1000);
    vector<double> x_cg = smat.solverCG(b, values, colIndices, rowPtr, 1e-6, 1000);
    vector<double> x_pcg = smat.solverPCG_Jacobi(b, values, colIndices, rowPtr, 1e-6, 1000);

    cout << "=== Jacobi Solution ===\n";
    for (double xi : x_jacobi) cout << xi << "\n";
    cout<<endl;

    cout << "=== Gauss-Sidel Solution ===\n";
    for (double xi : x_gs) cout << xi << "\n";
    cout<<endl;

     cout << "=== Conjugate-Gradient Solution ===\n";
    for (double xi : x_cg) cout << xi << "\n";
    cout<<endl;

    cout << "=== PCG (Jacobi) Solution ===\n";
    for (double xi : x_pcg) cout << xi << "\n";
    cout<<endl<<endl;

    return 0;
}
