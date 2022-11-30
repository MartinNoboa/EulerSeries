/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Euler en C
*
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define SIZE 10000000

double euler(double n, double sign) {
  double pi = 0;
  for (int i = 0; i <= SIZE; i++) {
        pi = pi + (sign * (4 / ((n) * (n + 1) * (n + 2))));
        sign = sign * (-1);
        n += 2;
    }
 
    return pi + 3;
}

int main(int argc, char* argv[]) {
  double n = 2, sign =1;
  int i;
  double ms, result;
	printf("Starting...\n");
	ms = 0;
	for (i = 0; i < N; i++) {
		start_timer();
		result = euler(n, sign);
		ms += stop_timer();
	}
  printf("Pi =  %0.9lf\n",result);
	printf("avg time = %.5lf ms\n", (ms / N));
  
  return 0;
}
