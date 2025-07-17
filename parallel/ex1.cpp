#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

int main()
{   
    omp_set_num_threads(4); // Request 4 threads

    // // Parallel computation 1
    // #pragma omp parallel
    // {
    //     #pragma omp single
    //     cout << "Actual threads used: " << omp_get_num_threads() << endl;
    // }

    // Initialize vectors
    vector<int> B{1,2,3,4,5,6,7,8,9,10};
    vector<int> C{1,2,3,4,5,6,7,8,9,10};
    int N = B.size();
    vector<int> A(N); // Allocate space for results
    int temp;

    // // Parallel computation 2
    // #pragma omp parallel for private(temp)
    // for (int i = 0; i < N; i++)
    // {   
    //     temp=B[i]*2;
    //     A[i] = temp + 1;

    //     #pragma omp critical
    //     cout << "Thread " << omp_get_thread_num() 
    //          << " computed A[" << i << "] = " << A[i] << "\n";
    // }

    // // parallel computation 3
    // // Each thread keeps a private sum, then combines at the end.
    // int sum=0;
    // #pragma omp parallel for reduction(+:sum)
    // for(int i=0;i<1000;i++)
    // {
    //     sum+=i; //thread safe
    // }
    // cout<<"Sum is "<<sum<<"\n";
    
    // parallel computation 4
    // Only one thread at a time can enter the critical section. critical (Safe, but slower)
    //  Avoid overusing this — it serializes the code.
    // int sum=0;
    // #pragma omp parallel for
    // for(int i=0;i<1000;i++)
    // {   
    //     #pragma omp critical
    //     sum+=i; //thread safe
    // }
    // cout<<"Sum is "<<sum<<"\n";

    // parallel computation 5 
    // atomic (For simple operations), Faster than critical — only works for single-variable updates like +=, ++, --.
    int sum=0;
    #pragma omp parallel for
    for(int i=0;i<1000;i++)
    {   
        #pragma omp atomic
        sum+=i; //thread safe
    }
    cout<<"Sum is "<<sum<<"\n";




    return 0;
}
