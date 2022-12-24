package com.epam.rd.autotasks;

public class DecrementingCarousel {
    protected final int[] array;
    private int currentSize = 0;
    protected boolean isRunning;


    public DecrementingCarousel(final int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException();
        }
        this.array = new int[capacity];
    }

    public boolean addElement(int element){
        if (element <= 0
                || currentSize == array.length
                || isRunning) {
            return false;
        }
        array[currentSize] = element;
        currentSize++;
        return true;
    }

    public CarouselRun run(){
        if (isRunning) {
            return null;
        }
        isRunning = true;
        return new CarouselRun(array);
    }
}