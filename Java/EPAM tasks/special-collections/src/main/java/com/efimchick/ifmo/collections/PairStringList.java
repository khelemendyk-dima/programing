package com.efimchick.ifmo.collections;

import java.util.*;

class PairStringList extends AbstractList<String> {
    List<String> list = new ArrayList<>();

    @Override
    public boolean add(String e) {
        list.add(e);
        return list.add(e);
    }

    @Override
    public void add(int index, String element) {
        if (index % 2 == 1) {
            list.add(index + 1, element);
            list.add(index + 1, element);
        } else {
            list.add(index, element);
            list.add(index, element);
        }
    }

    @Override
    public boolean addAll(Collection<? extends String> c) {
        if (c == null) {
            return false;
        }
        for (String s : c) {
            list.add(s);
            list.add(s);
        }
        return true;
    }

    @Override
    public boolean addAll(int index, Collection<? extends String> c) {
        if (c == null) {
            return false;
        }
        if (index % 2 == 1) {
            index++;
            for (String s : c) {
                list.add(index++, s);
                list.add(index++, s);
            }
        } else {
            for (String s : c) {
                list.add(index++, s);
                list.add(index++, s);
            }
        }
        return true;
    }

    @Override
    public boolean remove(Object o) {
        list.remove(o);
        return list.remove(o);
    }

    @Override
    public String remove(int index) {
        Object o = list.get(index);
        list.remove(o);
        index = list.indexOf(o);
        return list.remove(index);
    }

    @Override
    public void clear() {
        while (list.size() != 0) {
            list.remove(0);
        }
    }

    @Override
    public String get(int index) {
        return list.get(index);
    }

    @Override
    public String set(int index, String element) {
        if (index % 2 == 1) {
            list.set(index - 1, element);
            return  list.set(index, element);
        }
        list.set(index, element);
        return list.set(index + 1, element);
    }

    @Override
    public Iterator<String> iterator() {
        return list.iterator();
    }

    @Override
    public int size() {
        return list.size();
    }
}
