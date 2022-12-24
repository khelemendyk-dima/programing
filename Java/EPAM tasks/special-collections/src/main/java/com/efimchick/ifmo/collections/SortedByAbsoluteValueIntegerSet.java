package com.efimchick.ifmo.collections;

import java.util.AbstractSet;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

class SortedByAbsoluteValueIntegerSet extends AbstractSet<Integer> {
    Set<Integer> set = new HashSet<>();

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
