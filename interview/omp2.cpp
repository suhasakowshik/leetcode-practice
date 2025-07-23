#include<iostream>
#include<vector>
#include<omp.h>
using namespace std;

int main()
{
    const int N=1000;
    vector<int> data(N,1);

    int numThreads=omp_get_max_threads();
    vector<int> localSums(numThreads,0);

    #pragma omp parallel
    {
        int tid=omp_get_thread_num();

        #pragma omp for
        for(int i=0;i<N;i++)
        {
            localSums[tid]+=data[i];
        }
    }

    //merge in serial step
    int globalSum=0;
    for(int t=0;t<numThreads;t++)
    {
        globalSum+=localSums[t];
    }

    cout<<"Global Sum: "<<globalSum<<endl;
    return 0;
}