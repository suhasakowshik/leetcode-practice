#include<iostream>
#include<vector>
#include<algorithm>
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
        if(totalDOF!=y.size())
        {
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
    int numNodes=3;
    int systemDOF=1;

    SparseMatrix smat(numNodes,systemDOF);

    vector<vector<double>> ke={
        {10,-10},
        {-10,10}
    };

    vector<int> elemNodes1={0,1};
    vector<int> elemNodes2={1,2};


    smat.assembleElement(elemNodes1,ke);
    smat.assembleElement(elemNodes2,ke);

    //smat.printTriplets();

    vector<double> values;
    vector<int> colIndices;
    vector<int> rowPtr;

    smat.convertToCSR(values, colIndices, rowPtr);
    smat.printCSR(values, colIndices, rowPtr);

    vector<double> x = {1.0, 2.0, 3.0};  // Example input vector
    vector<double> y = smat.sparseMultiplyVector(x,values, colIndices, rowPtr);

    cout << "\n=== y = A * x ===\n";
    for (double v : y) cout << v << "\n";

    return 0;

}