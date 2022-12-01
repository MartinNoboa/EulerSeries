/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Nilkantha en C++
*
*--------------------------------------------------------------*/
#include <bits/stdc++.h>
#include "utils.h"
const int SIZE = 1000000; 
using namespace std;

class Nilkantha {
private:
	double result, sign, n;
public:
	Nilkantha(double s, double a) : sign(s), n(a),result(3) {}
	double getResult() const {
		return result;
	}
	void pi () {
		for (int i = 0; i <= SIZE; i++) {
			result = result+(sign * (4/((n)*(n + 1)*(n + 2))));
			sign = sign * (-1);
			n += 2;
		}
	}
};
int main(int argc, char* argv[]) {
	double ms;
	cout << "Starting..." << endl;
	ms = 0;
	Nilkantha obj(1, 2);
	for (int i = 0; i < 10; i++) {
		start_timer();
		obj.pi();
		ms += stop_timer();
	}
	cout << "pi = " << (double) obj.getResult() << endl;
	cout << "avg time = " << setprecision(15) << (ms / N) << " ms" << endl;

	return 0;
}
