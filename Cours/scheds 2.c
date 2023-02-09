#include <aux.h>






int main() {
int i;
#pragma omp parallel for num_threads(4) schedule(static,25)
for (i=0; i<400; i++)
  printf("%3d  %2d\n",i,omp_get_thread_num());
return 0;
}
