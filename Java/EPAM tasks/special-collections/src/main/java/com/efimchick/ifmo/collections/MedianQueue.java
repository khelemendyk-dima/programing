package com.efimchick.ifmo.collections;

import java.util.*;

class MedianQueue extends AbstractQueue<Integer> {
    private final PriorityQueue<Integer> left;
    private final PriorityQueue<Integer> right;

    public MedianQueue() {
        left = new PriorityQueue<>(Collections.reverseOrder());
        right = new PriorityQueue<>();
    }

    @Override
    public boolean offer(Integer integer) {
        if (integer == null) {
            return false;
        }
        if (right.size() > 0 && integer > right.peek()) {
            right.offer(integer);
        } else {
            left.offer(integer);
        }

        handleBalance();
        return true;
    }

    private void handleBalance() {
        if (left.size() - right.size() == 2) {
            right.offer(left.poll());
        } else if (right.size() - left.size() == 2) {
            left.offer(right.poll());
        }
    }

    @Override
    public Integer poll() {
        if (this.size() == 0) {
            return -1;
        } else if (left.size() >= right.size()) {
            return left.poll();
        } else {
            return right.poll();
        }
    }

    @Override
    public Integer peek() {
        if (this.size() == 0) {
            return -1;
        } else if (left.size() >= right.size()) {
            return left.peek();
        } else {
            return right.peek();
        }
    }

    @Override
    public Iterator<Integer> iterator() {
        return left.iterator();
    }

    @Override
    public int size() {
        return left.size() + right.size();
    }
}