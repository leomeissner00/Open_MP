#include <aux.h>






int main() {
int i;
printf("Hello %p\n",&i);
#pragma omp parallel
{
#pragma omp master
  {
    for(i=0; i<6; i++)
      {
#pragma omp task firstprivate(i)
        printf("Thread  %d   iteration: %d\n", omp_get_thread_num(), i);
      }
  }
}
return 0;
}
