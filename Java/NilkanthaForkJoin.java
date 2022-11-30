/*----------------------------------------------------------------
*
* Programación avanzada: Proyecto final
* Fecha: 30-Nov-2022
* Autor: A01704052 Martin Noboa
* Descripción: Implementacion secuencial de la serie de Nilkantha en Java Fork Join
*
*--------------------------------------------------------------*/
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;


public class NilkanthaForkJoin extends RecursiveTask<Double> {
	private static final int SIZE = 100_000_000;
	private static final int MIN = 10_000;
	private double result,n,sign;
	private int start, end;

	public NilkanthaForkJoin(int start, int end) {
		this.start = start;
		this.end = end;
	}

	public Double computeDirectly() {
		double result = 0;
		for (int i = start; i < SIZE; i++){
			this.result = this.result + (this.sign * (4 / ((this.n) * (this.n + 1) * (this.n + 2))));
			this.sign = this.sign * (-1);
			this.n += 2;
		}
		return result;
	}

	@Override
	protected Double compute() {
		if ((end - start) <= MIN) {
			return computeDirectly();
		} else {
			int mid = start + ((end - start) / 2);
			NilkanthaForkJoin lowerMid = new NilkanthaForkJoin(start, mid);
			lowerMid.fork();
			NilkanthaForkJoin upperMid = new NilkanthaForkJoin(mid, end);
			return (upperMid.compute() + lowerMid.join());
		}

	}

	public double getResult() {
		return result;
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		double acum = 0;
		double res = 0;
		ForkJoinPool pool;

		acum = 0;
		System.out.printf("Starting with %d threads\n", Utils.MAXTHREADS);

		for (int i = 0; i < Utils.N; i++) {
			res = 0;
			startTime = System.currentTimeMillis();

			pool = new ForkJoinPool(Utils.MAXTHREADS);
			res = pool.invoke(new NilkanthaForkJoin(0, SIZE));
			stopTime = System.currentTimeMillis();

			acum += (stopTime - startTime);
		}
		System.out.printf("sum = %d\n", res);
		System.out.printf("avg time = %.5f ms\n", (acum / Utils.N));
	}
}

