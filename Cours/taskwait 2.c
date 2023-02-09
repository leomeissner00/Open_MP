#include <aux.h>






int main() {
int x, y, z;

#pragma omp parallel
{
#pragma omp master
  {
#pragma omp task
    x = compute_one(0.2);

#pragma omp task
    y = compute_one(0.2);

#pragma omp taskwait
    z = x+y;
    printf("z is %d\n", z);
  }
}
return 0;
}
