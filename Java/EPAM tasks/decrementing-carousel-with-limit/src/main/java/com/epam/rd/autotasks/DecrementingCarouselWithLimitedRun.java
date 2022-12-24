package com.epam.rd.autotasks;

public class DecrementingCarouselWithLimitedRun extends DecrementingCarousel{
    private final int limit;
    public DecrementingCarouselWithLimitedRun(final int capacity, final int actionLimit) {
        super(capacity);
        this.limit = actionLimit;
    }

    @Override
    public CarouselRun run() {
        if (isRunning) {
            return null;
        }
        isRunning = true;
        return new CarouselWithLimitedRun(array, limit);
    }
}
