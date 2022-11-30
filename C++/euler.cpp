/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Euler en C++
*
*--------------------------------------------------------------*/


#include <bits/stdc++.h>
#include "utils.h"

const int SIZE = 5; 

using namespace std;

class Euler {
private:
	double result, sign, n;
public:
	Euler(double s, double a) : sign(s), n(a),result(3) {}

	double getResult() const {
		return result;
	}

	void euler () {
		for (int i = 0; i <= SIZE; i++) {
			result = result + (sign * (4 / ((n) * (n + 1)* (n + 2))));
			sign = sign * (-1);
			n += 2;
			
		}
	}
};

int main(int argc, char* argv[]) {
	double ms;

	cout << "Starting..." << endl;
	ms = 0;
	Euler obj(1, 2);
	for (int i = 0; i < 10; i++) {
		start_timer();
		obj.euler();
		ms += stop_timer();
	}
	cout << "pi = " << (double) obj.getResult() << endl;
	cout << "avg time = " << setprecision(15) << (ms / N) << " ms" << endl;

	return 0;
}
