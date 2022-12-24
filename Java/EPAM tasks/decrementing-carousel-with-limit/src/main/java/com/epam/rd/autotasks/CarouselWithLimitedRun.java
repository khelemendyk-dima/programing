package com.epam.rd.autotasks;

public class CarouselWithLimitedRun extends CarouselRun{
    private int limit;
    CarouselWithLimitedRun(final int[] array, final int actionLimit) {
        super(array);
        this.limit = actionLimit;
    }

    @Override
    public int next() {
        if (isFinished()) {
            return -1;
        }
        while (array[currentEl] == 0) {
            currentEl = (currentEl + 1) % array.length;
        }
        int res = array[currentEl];
        array[currentEl]--;
        currentEl = (currentEl + 1) % array.length;
        limit--;
        return res;
    }

    @Override
    public boolean isFinished() {
        if (limit == 0) {
            return true;
        }
        return super.isFinished();
    }
}
