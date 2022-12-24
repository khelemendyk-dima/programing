package com.epam.rd.java.basic.topic05.task03;

public class Task {

	private final int numberOfThreads;

	private final int numberOfIterations;

	private final int pause;

	private int c1;

	private int c2;

	public Task(int numberOfThreads, int numberOfIterations, int pause) {
		this.numberOfThreads = numberOfThreads;
		this.numberOfIterations = numberOfIterations;
		this.pause = pause;
	}

	public void compare() {
		resetCounters();

		Thread[] threads = new Thread[numberOfThreads];

		for (int i = 0; i < numberOfThreads; i++) {
			threads[i] = new Thread(this::compareAndDecrement);
			threads[i].start();
		}

		for (Thread thread : threads) {
			try {
				thread.join();
			} catch (InterruptedException e) {
				throw new RuntimeException(e);
			}
		}
	}

	private void resetCounters() {
		c1 = 0;
		c2 = 0;
	}

	public void compareSync() {
		resetCounters();

		Thread[] threads = new Thread[numberOfThreads];

		for (int i = 0; i < numberOfThreads; i++) {
			threads[i] = new Thread(() -> {
					synchronized (this) {
						compareAndDecrement();
					}
			});
			threads[i].start();
		}

		for (Thread thread : threads) {
			try {
				thread.join();
			} catch (InterruptedException e) {
				throw new RuntimeException(e);
			}
		}
	}

	private void compareAndDecrement() {
		for (int i = 0; i < numberOfIterations; i++) {
			System.out.println((c1 == c2) + " " + c1 + " " + c2);
			c1++;
			try {
					Thread.sleep(pause);
				} catch (InterruptedException e) {
					throw new RuntimeException(e);
				}
			c2++;
		}
	}

	public static void main(String[] args) {
		Task t = new Task(2, 5, 10);
		t.compare();
		System.out.println("~~~");
		t.compareSync();
	}

}
