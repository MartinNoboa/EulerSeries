/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Nilkantha en C++ con TBB
*
*--------------------------------------------------------------*/

#include <bits/stdc++.h>
// #include <tbb/parallel_reduce.h>
// #include <tbb/blocked_range.h>
#include "utils.h"

#define SIZE 100
using namespace std;
// using namespace tbb;

class NilkanthaTBB {
private:
	double result, sign,n;

public:
	NilkanthaTBB(double s, double a) : sign(s), n(a),result(3) {}
	// NilkanthaTBB(int *a, int size) : A(a), size(size), sign(1.0),result(3.0), n(0) {}
    // Even(Even &obj,split) : A(obj.A), size(obj.size),result(0) {}
    
	double getResult() const {
		return result;
	}

    // void operator() (const blocked_range<int> &r){
	// 	for (int i = r.begin(); i != r.end(); i++) {
	// 		if((A[i]%2)==0){
	// 			result +=1;
	// 		}
	// 	}
    // }

	void Nilkantha () {
		for (int i = 0; i <= SIZE; i++) {
			for (int i = 0; i <= SIZE; i++) {
				result = result + (sign * (4 / ((n) * (n + 1)* (n + 2))));
				sign = sign * (-1);
				n += 2;
			}
		}
	}

    void join(const NilkanthaTBB &x) {
		result += x.result;
	}
};

int main(int argc, char* argv[]) {
	double ms;
    double result;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
        // parallel_reduce(blocked_range<int>(0, SIZE), obj);
		// result = obj.getResult();
    	NilkanthaTBB obj(1,2);
		start_timer();
		obj.Nilkantha();
		ms += stop_timer();
		result = obj.getResult();
	}
	cout << "pi = " << result << endl;
	// cout << "result = "<< setprecision(15) << result<<endl;
	cout << "avg time = " << setprecision(15) << (ms / N) << " ms" << endl;

	return 0;
}