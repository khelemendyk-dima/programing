package com.epam.rd.java.basic.topic05.task05;

import java.io.*;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.List;

public class Task {
	
	public static final String FILE_NAME = "data.txt";
	
	private static RandomAccessFile raf;

	private static int resource = 0;

	private static int pause;

	private static int numberOfIterations;

	private static final String systemLineSeparator = System.lineSeparator();

	private static synchronized int getResource() {
		return resource++;
	}

	private static final Runnable myRunnable = () -> {
			int source = getResource();
			String out;
			for (int i = 0; i < numberOfIterations; i++) {
				try {
					synchronized (raf) {
						raf.seek((long) source * (numberOfIterations + systemLineSeparator.length()) + i);
						out = String.valueOf(source);
						out += (i == numberOfIterations - 1) ? systemLineSeparator : "";
						raf.writeBytes(out);
					}
					Thread.sleep(pause);
				} catch (InterruptedException | IOException e) {
					e.printStackTrace();
				}
			}
	};
 	
	public static void createRAF(int numberOfThreads, int numberOfIterations, int pause) throws IOException {
		// place your code here
		raf = new RandomAccessFile(FILE_NAME, "rw");
		raf.setLength(0);
		resource = 0;

		Task.pause = pause;
		Task.numberOfIterations = numberOfIterations;

		List<Thread> listOfThreads = new ArrayList<>();
		for (int i = 0; i < numberOfThreads; i++) {
			listOfThreads.add(new Thread(myRunnable));
			listOfThreads.get(i).start();
		}
		listOfThreads.forEach(thread -> {
			try	{
				thread.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		});
		raf.close();
	}

	public static void main(String[] args) throws IOException {
		createRAF(5, 20, 10);
		
		Files.readAllLines(Paths.get(FILE_NAME))
			.stream()
			.forEach(System.out::println);
	}
}
