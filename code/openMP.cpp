/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 19, 2023

* Autor: A01704052 Martin Noboa

* Archivo: OpenMP

*--------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <omp.h>
#include <math.h>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define MAXIMUM 1000000 //1e6
#define INCREMENT 2

double nilakantha(int maximum){
    double pi = 0;
    double sign = 1;
    double n = 2;
 	#pragma omp parallel for shared(maximum) reduction(+:result)
    for (int i = 0; i < MAXIMUM; i++) {
        pi += (sign*4)/((n)*(n+1)*(n+2));
        n+= INCREMENT;
        sign = sign * -1;
    }
    return pi;
}

int main(int argc, char* argv[]) {
	double pi;
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();
		pi = 3 + nilakantha(MAXIMUM);
		end = high_resolution_clock::now();
		timeElapsed += duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << fixed << setprecision(5) << pi <<  "\n";
	cout << "avg time = " << fixed << setprecision(3) << (timeElapsed / N) <<  " ms\n";

	return 0;
}