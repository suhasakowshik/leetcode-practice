#include<iostream>
#include<vector>
using namespace std;

//buiding triplet
struct Triplet
{
    int row;
    int col;
    double value;
};


class SparseMatrixCSR
{

public:
    int nRows,nCols;
    vector<double> values;
    vector<int> colIndices;
    vector<int> rowPtr;

    //costrutor to build CSR from dense matrix
    SparseMatrixCSR(const vector<vector<double>>& denseMatrix)
    {
        nRows=denseMatrix.size();
        nCols=denseMatrix[0].size();
        rowPtr.push_back(0); //starting is always 0

        for(int i=0;i<nRows;i++)
        {
            int nnzInRow=0;
            for(int j=0;j<nCols;j++)
            {
                double val=denseMatrix[i][j];
                //soring non zero values in the values of SCR
                if(val!=0)
                {
                    values.push_back(val);
                    colIndices.push_back(j);
                    nnzInRow++;
                }
            }

            rowPtr.push_back(rowPtr.back()+nnzInRow);
        }
    }

    //conver to triplets
    vector<Triplet> toTriplet()
    {
        vector<Triplet> triplets;
        for (int i = 0; i < nRows; i++)
        {
            for (int j = rowPtr[i]; j < rowPtr[i+1]; j++)
            {
                Triplet t;
                t.row = i;
                t.col = colIndices[j];
                t.value = values[j];
                triplets.push_back(t);
            }
        }
        return triplets;
    }


     void print()
    {
        cout << "=== CSR Storage ===" << endl;
        cout << "Values: ";
        for (double v : values) cout << v << " ";
        cout << "\nCol indices: ";
        for (int c : colIndices) cout << c << " ";
        cout << "\nRow pointer: ";
        for (int r : rowPtr) cout << r << " ";
        cout << "\n";
    }

};

int main()
{
    vector<vector<double>> dense = {
        {10, 0, 20},
        {0, 30, 0},
        {40, 0, 50}
    };

    SparseMatrixCSR mat(dense);
    mat.print();

    vector<Triplet> triplets=mat.toTriplet();
    cout << "\n=== Triplet format ===" << endl;
    for (const auto& t : triplets)
    {
        cout << "(" << t.row << "," << t.col << ") = " << t.value << endl;
    }

    return 0;
}