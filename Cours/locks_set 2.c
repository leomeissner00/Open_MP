#include <aux.h>






int main() {
omp_lock_t lock;
omp_init_lock(&lock);

#pragma omp parallel
{
  omp_set_lock(&lock);
  printf("%d: It's my turn to use the resource\n",omp_get_thread_num());
  use_resource();
  omp_unset_lock(&lock);
}

omp_destroy_lock(&lock);
return 0;
}
