#include <aux.h>






int main() {
#pragma omp parallel
{
  printf("Hello world from thread %2d in a pool of %2d.\n", omp_get_thread_num(), omp_get_num_threads());
}
return 0;
}
