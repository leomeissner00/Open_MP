#include <aux.h>






int main() {
  int iam;
  double t=secs();
#pragma omp parallel private(iam)
  {
    iam = omp_get_thread_num();

    if(iam==0){
      do_stuff(0.5); // 0.5 seconds
    } else {
      do_stuff(0.3); // 0.3 seconds
    }
#pragma omp barrier
    printf("Thread %2d reached this point at time %f.\n",iam,secs()-t);
  }
return 0;
}
