#include <aux.h>






int main() {
int iam, nth;

#pragma omp parallel
{
  iam = omp_get_thread_num();
  nth = omp_get_num_threads();
  do_stuff(1);
  printf("Hello world from thread %d in a pool of %2d.\n", iam, nth);
}
return 0;
}
