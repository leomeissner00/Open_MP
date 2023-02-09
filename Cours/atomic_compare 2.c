#include <aux.h>






int main() {
int i, n=1000, min=99999999;
int x[n];  

rand_fill(x, n);

#pragma omp parallel for
for(i=0; i<n; i++){
  #pragma omp atomic compare
  if (x[i] < min) { min = x[i]; }
  }

printf("Min is %d\n",min);

return 0;
}
