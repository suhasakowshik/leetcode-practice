#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

/*
In OpenMP, scheduling determines how iterations of a parallel for loop are divided among threads.
#pragma omp parallel for schedule(SCHEDULE_TYPE [, chunk_size])

Scheduling affects load balance, performance, and scalability

Best schedule depends on:

    Whether work per iteration is uniform or not

    How much overhead you can tolerate

static:- Each thread gets N/num_threads iterations. Uniform workload per iteration

dynamic:- Threads grab work as they finish, chunk by chunk. Load balancing

guided:- Like dynamic, but starts with large chunks and reduces gradually. Useful when early iterations are heavier .
            Reduces scheduling overhead vs pure dynamic

auto :- Leaves it to the OpenMP runtime to decide best strategy. Not optimal

runtime:- Scheduling strategy is picked at runtime using environment variables.
*/

int main()
{   
    omp_set_num_threads(4); // Request 4 threads

    vector<int> B{1,2,3,4,5,6,7,8,9,10};
    vector<int> C{1,2,3,4,5,6,7,8,9,10};
    int N = B.size();
    vector<int> A(N); 

    // int sum=0;
    // #pragma omp parallel for schedule(static)
    // for(int e=0;e<N;e++)
    // {
    //     sum+=e;
    // }
    // cout<<"Sum is "<<sum<<"\n";

    // int sum=0;
    // #pragma omp parallel for schedule(dynamic,4)
    // for(int e=0;e<N;e++)
    // {
    //     sum+=e;
    // }
    // cout<<"Sum is "<<sum<<"\n";


    // int sum=0;
    // #pragma omp parallel for schedule(dynamic,4)
    // for(int e=0;e<N;e++)
    // {
    //     sum+=e;
    // }
    // cout<<"Sum is "<<sum<<"\n";

    // int sum=0;
    // #pragma omp parallel for schedule(guided)
    // for(int e=0;e<N;e++)
    // {
    //     sum+=e;
    // }
    // cout<<"Sum is "<<sum<<"\n";

    int sum=0;
    #pragma omp parallel for schedule(auto)
    for(int e=0;e<N;e++)
    {
        sum+=e;
    }
    cout<<"Sum is "<<sum<<"\n";

    return 0;

}