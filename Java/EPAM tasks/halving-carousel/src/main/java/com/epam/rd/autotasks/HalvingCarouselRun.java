package com.epam.rd.autotasks;

public class HalvingCarouselRun extends CarouselRun {

    HalvingCarouselRun(int[] array) {
        super(array);
    }

    @Override
    public int next() {
        if (findCurrentEl() == -1) {
            return -1;
        }
        int res = array[currentEl];
        array[currentEl] /= 2;
        currentEl = (currentEl + 1) % array.length;
        return res;
    }
}
