/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Nilkantha en Java
*
*--------------------------------------------------------------*/


public class NilkanthaThreads extends Thread {
	private static final int SIZE = 100_000_000;
	private double result,n,sign;
	private int end;

	public NilkanthaThreads(int blockSize, int n,double s) {
		this.n = n;
		this.sign = s;
		this.result = 0;
		this.end = blockSize;
	}

	public double getResult() {
		return result;
	}

	public void calculate() {
		for (int i = 0; i < end; i++){
			this.result = this.result + (this.sign * (4 / ((this.n) * (this.n + 1) * (this.n + 2))));
			this.sign = this.sign * (-1);
			this.n += 2;
		}
	}

	public void run() {
		calculate();
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		double acum = 0;
		double res = 0;
		double s = 1;

		NilkanthaThreads threads[] = new NilkanthaThreads[Utils.MAXTHREADS];
		int blockSize = SIZE / Utils.MAXTHREADS;

		acum = 0;
		System.out.printf("Starting with %d threads\n", Utils.MAXTHREADS);
		for (int i = 0; i < Utils.N; i++) {
			res = 0;
			startTime = System.currentTimeMillis();

			for (int j = 1; j < threads.length+1; j++) {
				s = 1;
				if ((j-1) % 2 == 0){
					s = -1;
				}
				threads[j-1] = new NilkanthaThreads(blockSize, (2+2*j),1);
				threads[j-1].start();
			}
			try {
				for (int j = 0; j < threads.length; j++) {
					threads[j].join();
					res += threads[j].getResult();
				}
			} catch (InterruptedException ie) {
				ie.printStackTrace();
			}

			stopTime = System.currentTimeMillis();

			acum += (stopTime - startTime);
		}
		res += 3;
		System.out.printf("sum = %f\n", res);
		System.out.printf("avg time = %.5f ms\n", (acum / Utils.N));
	}
}

