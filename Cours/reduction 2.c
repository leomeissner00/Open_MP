#include <aux.h>






int main() {
    int i, sum, n=1000;
    int x[n];  

    rand_fill(x, n); sum=0;

#pragma omp parallel for reduction(+:sum)
    for(i=0; i<n; i++){
       sum += x[i];
    }

    printf("Sum is %d\n",sum);

return 0;
}
