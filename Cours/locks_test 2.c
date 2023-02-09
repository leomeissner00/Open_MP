#include <aux.h>






int main() {
omp_lock_t lock;
omp_init_lock(&lock);

#pragma omp parallel
{

  while(!omp_test_lock(&lock)){
    /* if lock is already locked, I do some other useful stuff */
    printf("%d: lock is busy, I do some stuff\n",omp_get_thread_num());
    do_stuff(0.5);
  }

  printf("%d: It's my turn to use the resource\n",omp_get_thread_num());
  use_resource();
  omp_unset_lock(&lock);
}

omp_destroy_lock(&lock);
return 0;
}
