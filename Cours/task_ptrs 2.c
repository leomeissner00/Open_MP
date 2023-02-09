#include <aux.h>






int main() {
int x[2]={0,0};
int *p=x;
double t=secs();
#pragma omp parallel
{
#pragma omp master
  {
#pragma omp task firstprivate(p) depend(out:*p)
    *p = compute_one(1.0);

    p+=1;

#pragma omp task firstprivate(p) depend(out:*p)
    *p = compute_one(1.0);

#pragma omp taskwait
    printf("x: {%d,%d} (correct value is {1,1}) and time is %f\n",x[0],x[1],secs()-t);
  }
}
return 0;
}
