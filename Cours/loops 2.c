#include <aux.h>






int main() {
int i, n=4;
int a[n], b[n], c[n];

#pragma omp parallel private(i)
{

  for (i=0; i<n; i++) {
    printf("Thread %2d does iteration %2d\n",omp_get_thread_num(),i);
    a[i] += b[i]+c[i];
  }
}
return 0;
}

#include <aux.h>






int main() {
int i, n=4;
int a[n], b[n], c[n];

#pragma omp parallel
{
#pragma omp for
  for (i=0; i<n; i++) {
    printf("Thread %2d does iteration %2d\n",omp_get_thread_num(),i);
    a[i] += b[i]+c[i];
  }
}
return 0;
}
