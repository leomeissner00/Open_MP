#include <aux.h>






int main() {
int iam, nth, n=4;

#pragma omp parallel
{
  printf("Region 1 thread %2d / %2d.\n", omp_get_thread_num(), omp_get_num_threads());
}

omp_set_num_threads(n);

#pragma omp parallel
{
  printf("Region 2 thread %2d / %2d.\n", omp_get_thread_num(), omp_get_num_threads());
}

#pragma omp parallel num_threads(2)
{
  printf("Region 3 thread %2d / %2d.\n", omp_get_thread_num(), omp_get_num_threads());
}

#pragma omp parallel if(n<5)
{
  printf("Region 4 thread %2d / %2d.\n", omp_get_thread_num(), omp_get_num_threads());
}


return 0;
}
