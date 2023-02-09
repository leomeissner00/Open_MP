#include <aux.h>






int main() {
double w=0.4;

#pragma omp parallel
{
#pragma omp master
  {
#pragma omp task
    printf("Thread  %d executes this first task\n", omp_get_thread_num());

#pragma omp task if(w>0.4)
    {
      do_stuff(w);
      printf("Thread  %d executes this second task\n", omp_get_thread_num());
    }

  }
}
return 0;
}
