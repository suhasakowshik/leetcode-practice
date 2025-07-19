#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class CSR
{   
private:
    vector<double> values;
    vector<int> colIndex;
    vector<int> rowPtr;
    int rows,cols;

public:
    CSR(const vector<vector<double>>& A)
    {
        rows=A.size();
        cols=A[0].size();
        rowPtr.push_back(0);

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(A[i][j]!=0)
                {
                    values.push_back(A[i][j]);
                    colIndex.push_back(j);
                }
            }
            rowPtr.push_back(values.size());
        }

    }

    vector<double> multiply(const vector<double>& x) const
    {
        vector<double> result(rows,0.0);
        for(int i=0;i<rows;i++)
        {
            for(int j=rowPtr[i];j<rowPtr[i+1];j++)
            {
                result[i]+=values[j]*x[colIndex[j]];
            }
        }

        return result;
    }

    void printInternalData() const
    {
        cout << "CSR - values: ";
        for (auto v : values) cout << v << " ";
        cout << "\nCSR - colIndex: ";
        for (auto c : colIndex) cout << c << " ";
        cout << "\nCSR - rowPtr: ";
        for (auto r : rowPtr) cout << r << " ";
        cout << "\n";
    }
};

class CSC
{

private:
    vector<double> values;
    vector<int> rowIndex;
    vector<int> colPtr;
    int rows,cols;

public:
    CSC(vector<vector<double>>& A)
    {
        rows=A.size();
        cols=A[0].size();
        colPtr.push_back(0);

        for(int j=0;j<cols;j++)
        {
            for(int i=0;i<rows;i++)
            {
                if(A[i][j]!=0)
                {
                    values.push_back(A[i][j]);
                    rowIndex.push_back(i);
                }
            }

            colPtr.push_back(values.size());
        }
    }

    vector<double> multiply(const vector<double>& x) const
    {
        vector<double> result(rows,0.0);
        for(int j=0;j<cols;j++)
        {
            for(int i=colPtr[j];i<colPtr[j+1];i++)
            {
                result[rowIndex[i]]+=values[i]*x[j];
            }
        }

        return result;
    }

    void printInternalData() const 
    {
        cout << "CSC - values: ";
        for (auto v : values) cout << v << " ";
        cout << "\nCSC - rowIndex: ";
        for (auto r : rowIndex) cout << r << " ";
        cout << "\nCSC - colPtr: ";
        for (auto c : colPtr) cout << c << " ";
        cout << "\n";
    }
};

int main()
{
    vector<vector<double>> A = 
    {
        {10, 0, 0, 0},
        {0, 0, 20, 0},
        {0, 30, 0, 40},
        {50, 0, 0, 60}
    };

    vector<double> x={1,2,3,4};

    //CSR
    CSR csr(A);
    auto resultCSR=csr.multiply(x);

    cout << "CSR A·x = ";
    for (double val : resultCSR) cout << val << " ";
    cout << "\n";
    csr.printInternalData();

    //CSC
    CSC csc(A);
    auto resultCSC=csc.multiply(x);

    cout << "\nCSC A·x = ";
    for (double val : resultCSC) cout << val << " ";
    cout << "\n";
    csc.printInternalData();

    cout<<endl;

    return 0;
}