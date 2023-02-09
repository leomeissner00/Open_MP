#include <aux.h>






int main() {
  int iam;

#pragma omp parallel private(iam)
  {
    iam = omp_get_thread_num();

#pragma omp single nowait
    {
      do_stuff(0.1);
      printf(" ---> This is only done by: %2d\n",iam);
    }
    printf("      This is also done by: %2d.\n",iam);
  }
return 0;
}
