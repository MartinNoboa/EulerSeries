/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 13, 2023

* Autor: A01704052 Martin Noboa

* Archivo: Java Fork Join

*--------------------------------------------------------------*/

import java.util.concurrent.RecursiveTask;
import java.util.concurrent.ForkJoinPool;
import java.util.Arrays;

public class ForkJoin extends RecursiveTask<Double> {
	private static final int SIZE = 100_000_000;
	private static final int MIN = 10_000;
	private int start, end;
    public double sign, n;

	public ForkJoin(int start, int end) {
		this.start = start;
		this.end = end;
        this.start = start;
        this.end = end;
        this.n = start + 2;
        if (start+2 % 2 == 0){
            this.sign = 1.0;
        }else{
            this.sign = -1.0;
        }
	}

	public double calculate() {
		double pi = 0;
        for (int i = this.start; i < this.end; i++) {
            pi += (this.sign * 4)/ (this.n*(this.n+1)*(this.n+2));
            this.sign = this.sign * -1;
            this.n += 2;
        }
        return pi;
    }
	

	@Override
	protected Double compute() {
		if ( (end - start) <= MIN ) {
			return calculate();
		} else {
			int mid = start + ( (end - start) / 2 );
			ForkJoin lowerMid = new ForkJoin(start, mid);
			lowerMid.fork();
			ForkJoin upperMid = new ForkJoin(mid, end);
			return upperMid.compute() + lowerMid.join();
		}
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		double result = 0, elapsedTime;
		int blockSize;
		ForkJoinPool pool;
		
		elapsedTime = 0;
		
		System.out.printf("Starting...\n");
		for (int i = 0; i < Utils.N; i++) {
			startTime = System.currentTimeMillis();
            pool = new ForkJoinPool(Utils.MAXTHREADS);
			result = 3 + pool.invoke(new ForkJoin(0, SIZE));

			stopTime = System.currentTimeMillis();

			elapsedTime += (stopTime - startTime);
		}
		System.out.printf("result = %.5f\n", result);
		System.out.printf("avg time = %.5f ms\n", (elapsedTime / Utils.N));
	}
}