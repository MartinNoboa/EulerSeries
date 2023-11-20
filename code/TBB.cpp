/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 19, 2023

* Autor: A01704052 Martin Noboa

* Archivo: C++ TBB

*--------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#include <tbb/parallel_for.h>
#include "utils.h"

using namespace std;
using namespace std::chrono;
using namespace tbb;

#define MAXIMUM 100000000

// implement your code
class Exercise02{
private: 
    double pi;

public:
    Exercise02(): pi(0){}
    Exercise02(Exercise02 &other, split): pi(0){}

    double getResult() const {
        return pi;
    }

    void operator() (const blocked_range<int> &r) {
        double sign = 1.0;
        double n = 2;
        for (int i = r.begin(); i != r.end(); i++) {
            pi += (sign*4)/(i*2+2)/(i*2+3);
            sign = sign * -1; 
            n +=2;    
        }
    }

    void join(const Exercise02 &other) {
		pi += other.pi;
	}
};

int main(int argc, char* argv[]) {
	double result;
	// These variables are used to keep track of the execution time.
	high_resolution_clock::time_point start, end;
	double timeElapsed;

	cout << "Starting...\n";
	timeElapsed = 0;
	for (int j = 0; j < N; j++) {
		start = high_resolution_clock::now();

		// call the implemented function
        Exercise02 obj;
        parallel_reduce(blocked_range<int>(0, MAXIMUM),obj);
        result = 3.0 + obj.getResult();

		end = high_resolution_clock::now();
		timeElapsed += 
			duration<double, std::milli>(end - start).count();
	}
    cout << "result = " << fixed << setprecision(5) << result << "\n";
	cout << "avg time = " << fixed << setprecision(3) 
		 << (timeElapsed / N) <<  " ms\n";

	return 0;
}