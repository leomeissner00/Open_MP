#include <aux.h>






int main() {
  double t_start=secs(), t_end;
  int i, n=100, m=5, tot=0, x[5]={0,0,0,0,0};

#pragma omp parallel for
    for(i=0; i<n; i++){
#pragma omp atomic update
      x[rnd_int()%m] += compute_one(0.01);
    }
  t_end = secs()-t_start;

  for(i=0; i<m; i++)
    tot += x[i];
  printf("\nTot:%10d   time:%f\n",tot, t_end);
return 0;
}
