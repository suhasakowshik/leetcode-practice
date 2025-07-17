#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

/*

private(var):-  Each thread gets its own uninitialized copy of var.
                The value of var is not carried from outside the parallel region.
                Each thread has its own x
                Prevents race condition
                Initial value of x is garbage unless assigned inside

firstprivate(var):- Like private, but initializes each thread’s copy with the original value.
                    For example, Each thread starts with x = 5
                    Then modifies its local copy
                    Very useful when threads need a copy of constant input (like parameters)

lastprivate(var):- Used in for loops. 
                   The value from the last iteration of the loop is assigned to the original variable after the loop ends.
                   Only one thread executes the last iteration — its value is saved.
                   Use this when you want to keep result from final iteration.


*/

int main()
{
    int x=5;
    omp_set_num_threads(4);

    // #pragma omp parallel for firstprivate(x)
    // for(int i=0;i<4;i++)
    // {
    //     x+=i;
    //     cout << "Thread " << omp_get_thread_num() << ": x = " << x << "\n";
    // }

    // #pragma omp parallel for firstprivate(x)
    // for(int i=0;i<4;i++)
    // {
    //    x += i;
    //    cout << "Thread " << omp_get_thread_num() << ": x = " << x << "\n";
    // }

    int lastVal=-1;
    #pragma omp parallel for lastprivate(lastVal)
    for(int i=0;i<4;++i)
    {
       lastVal=i*2;
       std::cout << "Thread " << omp_get_thread_num() << ": lastVal = " << x << "\n";
    }
    std::cout << "Last value: " << lastVal << "\n";

    return 0;
    
}