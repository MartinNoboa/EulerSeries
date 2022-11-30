#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define SIZE 100000000

double euler(double n, double sign) {
  double pi = 0;
  int i;

  #pragma omp parallel for reduction(+:pi)
  for (i = 0; i <= SIZE; i++) {
        pi = pi + (sign * (4 / ((n) * (n + 1) * (n + 2))));
        sign = sign * (-1);
        n += 2;
    }
 
    return pi;
}

int main(int argc, char* argv[]) {
  int i;
  double n = 2, sign =1;
  double ms, sum;

  printf("\nOpenMP \n");

	printf("Starting...\n");
	ms = 0;
	for (i = 0; i < N; i++) {
		start_timer();
		sum = euler(n, sign);
		ms += stop_timer();
	}
  sum += 3;
	printf("count = %.8f\n", sum);
	printf("avg time = %.5lf ms\n", (ms / N));
  
  return 0;
}
