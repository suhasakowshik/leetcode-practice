#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;


/*

Control or Syncronization

barrier:- Forces all threads to wait at that point before continuing.
          All threads reach the barrier, and none proceeds until all arrive.
          Ensure synchronization between phases of computation, like FEM time steps or coupled solvers.

nowait:- Used with for or sections to skip the implicit barrier at the end of the loop or section block.
         
          Use nowait to remove unnecessary waits:

            When threads have independent work to do after loop

            Reduces overhead

sections:- Divide work into distinct code blocks (not loop-based) for parallel execution.
            sections is for task parallelism, not data parallelism (not for for loop)
*/

int main()
{   
    // #pragma omp parallel
    // {
    //     int tid=omp_get_thread_num();
    //     cout<<"\n Thread "<<tid<<" finished part A\n";

    //     #pragma omp barrier
    //     cout<<"\n Thread "<<tid<<" starting part B\n";
    // }

    // #pragma omp parallel
    // {   
    //     #pragma omp for nowait
    //     for(int i=0;i<4;i++)
    //     {
    //         cout << "Thread " << omp_get_thread_num() << " handles i=" << i << "\n";
    //     }

    //      // Thread does not wait — moves on immediately
    //     cout<< "Thread " << omp_get_thread_num() << " continues...\n";
    // }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::cout << "Thread " << omp_get_thread_num() << " solves fluid\n";
        }

        #pragma omp section
        {
            std::cout << "Thread " << omp_get_thread_num() << " solves structure\n";
        }

        #pragma omp section
        {
            std::cout << "Thread " << omp_get_thread_num() << " computes post-process\n";
        }
    }

    cout<<endl;

    return 0;
}