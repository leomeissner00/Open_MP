#include <aux.h>






int main() {
  int iam;
  double t=secs();

#pragma omp parallel private(iam)
  {
    iam = omp_get_thread_num();

#pragma omp critical (toti)
    {
      do_stuff(0.1);
      printf("First  is done by %2d  at time %f\n",iam, secs()-t);
    }

#pragma omp critical (toto)
    {
      do_stuff(0.1);
      printf("Second is done by %2d  at time %f\n",iam, secs()-t);
    }
  }
return 0;
}
