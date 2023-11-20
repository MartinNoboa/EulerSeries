/*----------------------------------------------------------------

*

* Programación avanzada: Proyecto final

* Fecha: Noviembre 13, 2023

* Autor: A01704052 Martin Noboa

* Archivo: Java Threads

*--------------------------------------------------------------*/

public class Threads extends Thread {
	private static final int SIZE = 100_000_000;
	private int start, end;
	public double pi, sign, n;

	public Threads(int start, int end) {
        this.start = start;
        this.end = end;
        this.n = start + 2;
        if (start+2 % 2 == 0){
            this.sign = 1.0;
        }else{
            this.sign = -1.0;
        }
        this.pi = 0.0;
	}

    public double getResult() {
        return pi;
    }

	public void run() {
        for (int i = this.start; i < this.end; i++) {
            this.pi += (this.sign * 4)/ (this.n*(this.n+1)*(this.n+2));
            this.sign = this.sign * -1;
            this.n += 2;
        }
	}

	public static void main(String args[]) {
		long startTime, stopTime;
		double result = 3, elapsedTime;
		int blockSize;
		Threads threads[];
		
		// place yout code here
        blockSize = SIZE / Utils.MAXTHREADS;
        threads = new Threads[Utils.MAXTHREADS];


		elapsedTime = 0;
		System.out.printf("Starting...\n");
		for (int i = 0; i < Utils.N; i++) {
			startTime = System.currentTimeMillis();

			// place yout code here
            for (int j = 0; j < threads.length; j++) {
                threads[j] = new Threads(j * blockSize, (j + 1) * blockSize);
            }

            for (int j = 0; j < threads.length; j++) {
                threads[j].start();
            }
            double sign = 1.0;
            for (int j = 0; j < threads.length; j++) {
                try {
                    threads[j].join();
                    result += sign* threads[j].getResult();
                    sign = sign * -1;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

			stopTime = System.currentTimeMillis();

			elapsedTime += (stopTime - startTime);
		}
		System.out.printf("result = %.5f\n", result);
		System.out.printf("avg time = %.3f ms\n", (elapsedTime / Utils.N));
	}
}