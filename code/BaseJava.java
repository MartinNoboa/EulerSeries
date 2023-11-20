/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 13, 2023

* Autor: A01704052 Martin Noboa

* Archivo: Java Secuencial

*--------------------------------------------------------------*/

import java.lang.Math;
public class BaseJava {
	private static final int MAX = 100_000_000;

	public BaseJava() {
	}

	public long calculate() {
		long pi = 0.0, sign = 1.0, n = 2.0;
        for (int i = 0; i < this.MAX; i++) {
            pi += (sign * 4)/ (n*(n+1)*(n+2));
            sign = sign * -1;
            n += 2;
        }
        return 3 + pi;
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		long pi=0, elapsedTime;
		
		BaseJava obj = new BaseJava();

		elapsedTime = 0;
		System.out.printf("Starting...\n");
		for (int i = 0; i < Utils.N; i++) {
			startTime = System.currentTimeMillis();

			pi = obj.calculate();

			stopTime = System.currentTimeMillis();

			elapsedTime += (stopTime - startTime);
		}
		System.out.printf("result = %.5f\n", pi);
		System.out.printf("avg time = %.3f ms\n", (elapsedTime / Utils.N));
	}
}