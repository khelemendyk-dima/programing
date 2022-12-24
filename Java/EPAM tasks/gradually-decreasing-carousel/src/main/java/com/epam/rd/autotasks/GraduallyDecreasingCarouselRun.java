package com.epam.rd.autotasks;

public class GraduallyDecreasingCarouselRun extends CarouselRun{
    private int currDecrement = 1;
    GraduallyDecreasingCarouselRun(final int[] array) {
        super(array);
    }
    @Override
    public int next() {
        if (isFinished()) {
            return -1;
        }
        while (array[currentEl] == 0) {
            currentEl++;
            if (currentEl == array.length) {
                currentEl %= array.length;
                currDecrement++;
            }
        }
        int res = array[currentEl];
        array[currentEl] -= currDecrement;
        if (array[currentEl] < 0) {
            array[currentEl] = 0;
        }
        currentEl++;
        if (currentEl == array.length) {
            currentEl %= array.length;
            currDecrement++;
        }

        return res;
    }
}
