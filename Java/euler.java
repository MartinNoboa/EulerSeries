/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Euler en Java
*
*--------------------------------------------------------------*/
import java.util.*;

public class Euler {
	private static final int SIZE = 100;
	private double result,n,sign;

	public Euler() {
		this.n = 2;
		this.sign = 1;
		this.result = 3;
	}

	public double getResult() {
		return result;
	}

	public void calculate() {
		for (int i = 0; i <= 1000000; i++) {
			this.result = this.result + (this.sign * (4 / ((this.n) * (this.n + 1) * (this.n + 2))));
			this.sign = this.sign * (-1);
			this.n += 2;
		}
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		double acum = 0;

		Euler e = new Euler();
		System.out.printf("Starting...\n");

		for (int i = 0; i < 10; i++) {
			startTime = System.currentTimeMillis();
			e.calculate();
			stopTime = System.currentTimeMillis();
			acum += (stopTime - startTime);
		}
		System.out.printf("Pi = %.8f\n", e.getResult());
		System.out.printf("avg time = %.10f ms\n", (acum / 10));
	}
}
