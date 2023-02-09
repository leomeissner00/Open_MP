#include <aux.h>






int main() {
int a, b, c, x, y;
double t=secs();
#pragma omp parallel
{
#pragma omp master
  {
#pragma omp task depend(out:b) priority(2)
    b = f_b();

#pragma omp task depend(out:c) priority(2)
    c = f_c();

#pragma omp task depend(out:a)
    a = f_a();

#pragma omp task depend(in:b,c) depend(out:x)
    x = f_x(b, c);

#pragma omp task depend(in:a,x) depend(out:y)
    y = f_y(a, x);

#pragma omp taskwait
    printf("y: %d (correct value is 9) and time is %f\n",y,secs()-t);
  }
}
return 0;
}
