package com.epam.autotasks.collections;

import java.util.*;

class RangedOpsIntegerSet extends AbstractSet<Integer> {
    Set<Integer> set = new TreeSet<>();
    public boolean add(int fromInclusive, int toExclusive) {
        boolean isAdded = false;
        for (int i = fromInclusive; i < toExclusive; i++) {
            if (!contains(i)) {
                set.add(i);
                isAdded = true;
            }
        }
        return isAdded;
    }

    public boolean remove(int fromInclusive, int toExclusive) {
        boolean isRemoved = false;
        for (int i = fromInclusive; i < toExclusive; i++) {
            if (contains(i)) {
                set.remove(i);
                isRemoved = true;
            }
        }
        return isRemoved;
    }

    @Override
    public boolean add(final Integer integer) {
        return set.add(integer);
    }

    @Override
    public boolean remove(final Object o) {
        return set.remove(o);
    }

    @Override
    public Iterator<Integer> iterator() {
        return set.iterator();
    }

    @Override
    public int size() {
        return set.size();
    }
}
