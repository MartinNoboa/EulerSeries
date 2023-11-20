/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 13, 2023

* Autor: A01704052 Martin Noboa

* Archivo: C++ Secuencial

*--------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include <math.h>
#include "utils.h"

using namespace std;
using namespace std::chrono;

#define MAXIMUM 100000000
#define INCREMENT 2

double nilakantha() {
    double piAprox = 0;
    double sign = 1;
    double n = 2;
    for (int i = 0; i < MAXIMUM; i++) {
        piAprox += (sign*4)/((n)*(n+1)*(n+2));
        n+= INCREMENT;
        sign = sign * -1;
    }
    return 3 + piAprox;
}

int main(int argc, char* argv[]) {
	double pi;

	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();

		// call the implemented function
        pi = nilakantha();

		end = high_resolution_clock::now();
		timeElapsed += duration<double, std::milli>(end - start).count();
	}
	cout << "result = " << fixed << setprecision(4) << pi << "\n";
	cout << "avg time = " << fixed << setprecision(3) << (timeElapsed / N) <<  " ms\n";

	return 0;
}