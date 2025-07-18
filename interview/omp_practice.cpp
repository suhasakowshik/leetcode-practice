#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<omp.h>
using namespace std;


void serialMatMul(const vector<vector<double>>& A,
                  const vector<vector<double>>& B,
                  vector<vector<double>>& C,
                  int M, int K, int N)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {   
            double sum=0.0;
            for(int k=0;k<K;k++)
            {
                sum += A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
}

void parallelMatMul(const vector<vector<double>>& A,
                  const vector<vector<double>>& B,
                  vector<vector<double>>& C,
                  int M, int K, int N)
{   
    #pragma omp parallel for collapse(2)
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {   
            double sum=0.0;
            for(int k=0;k<K;k++)
            {
                sum+=A[i][k]*B[k][j];
            }
            C[i][j]=sum;
        }
    }
    
}

vector<vector<double>> generateRandomMatrix(int M,int N,double minVal,double maxVal)
{
    vector<vector<double>> mat(M,vector<double>(N));
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(minVal,maxVal);

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            mat[i][j] = dis(gen);
        }
    }
    
    return mat;
}

int main()
{   
    int total_threads=16;
    int M=1600,K=1000,N=2000;

    auto A=generateRandomMatrix(M,K,-1.0,1.0);
    auto B=generateRandomMatrix(K,N,-30.0,2.0);
    

    //serial compute
    vector<std::vector<double>> C(M, vector<double>(N, 0.0));
    auto start_s=chrono::high_resolution_clock::now();
    serialMatMul(A,B,C,M,K,N);
    auto stop_s=chrono::high_resolution_clock::now();

    chrono::duration<double,milli> duration_s=stop_s-start_s;
    cout<<"Serial Matrix multiplication time: "<<duration_s.count()<<" ms\n";
    cout<<endl;

    for(int i=2;i<=total_threads;i++)
    {   
        // set threads usage
        omp_set_num_threads(i);

        vector<std::vector<double>> C(M, vector<double>(N, 0.0));

        //parallel compute
        auto start_p=chrono::high_resolution_clock::now();
        parallelMatMul(A,B,C,M,K,N);
        auto stop_p=chrono::high_resolution_clock::now();

        chrono::duration<double,std::milli> duration_p=stop_p-start_p;
        cout<<"Parallel Matrix multiplication time: "<<duration_p.count()<<" ms "<<"using "<<i<<" threads\n";
        double speedup = duration_s.count()/duration_p.count();
        cout << "Speedup: " << speedup << "x\n";
        cout<<endl;
    }

    return 0;

}