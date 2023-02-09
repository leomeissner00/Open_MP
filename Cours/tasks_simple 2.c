#include <aux.h>






int main() {
#pragma omp parallel
{
#pragma omp master
  {
#pragma omp task
    printf("Thead %2d does task 1\n",omp_get_thread_num());

#pragma omp task
    printf("Thead %2d does task 2\n",omp_get_thread_num());

#pragma omp task
    printf("Thead %2d does task 3\n",omp_get_thread_num());

#pragma omp task
    printf("Thead %2d does task 4\n",omp_get_thread_num());
  }
}
return 0;
}
