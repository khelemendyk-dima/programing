package com.epam.autotasks.collections;

import java.util.*;

class IntStringCappedMap extends AbstractMap<Integer, String> {

    private final long capacity;
    private final Map<Integer, String> map;
    private final List<Integer> listOfKeys;

    public IntStringCappedMap(final long capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.listOfKeys = new ArrayList<>();
    }

    public long getCapacity() {
        return capacity;
    }

    @Override
    public Set<Entry<Integer, String>> entrySet() {
        return new AbstractSet<>() {
            @Override
            public Iterator<Entry<Integer, String>> iterator() {
                return new Iterator<>() {
                    final Iterator<Entry<Integer, String>> it = map.entrySet().iterator();
                    @Override
                    public boolean hasNext() {
                        // implement this method
                        return it.hasNext();
                    }

                    @Override
                    public Entry<Integer, String> next() {
                        // implement this method
                        return it.next();
                    }
                };
            }

            @Override
            public int size() {
                return IntStringCappedMap.this.size();
            }
        };
    }

    @Override
    public String get(final Object key) {
        //implement this method
        return map.get(key);
    }

    @Override
    public String put(final Integer key, final String value) {
        //implement this method
        if (value.length() > capacity) {
            throw new IllegalArgumentException();
        }

        long currentSizeOfValues = getCurrentSizeOfValues();

        if (map.containsKey(key) && currentSizeOfValues - map.get(key).length() + value.length() <= capacity) {
            listOfKeys.remove(key);
            listOfKeys.add(key);
            return map.put(key, value);
        }
        if (currentSizeOfValues + value.length() > capacity) {
            while (currentSizeOfValues + value.length() > capacity) {
                if (map.containsKey(key) && currentSizeOfValues - map.get(key).length() + value.length() <= capacity) {
                    listOfKeys.remove(key);
                    listOfKeys.add(key);
                    return map.put(key, value);
                }
                currentSizeOfValues -= map.get(listOfKeys.get(0)).length();
                map.remove(listOfKeys.get(0));
                listOfKeys.remove(0);
            }
        }

        listOfKeys.add(key);
        return map.put(key, value);
    }

    @Override
    public String remove(final Object key) {
        //implement this method
        listOfKeys.remove((Integer)key);
        return map.remove(key);
    }

    @Override
    public int size() {
        //implement this method
        return map.size();
    }

    private long getCurrentSizeOfValues() {
        long size = 0;

        for (Entry<Integer, String> entry : map.entrySet()) {
            size += entry.getValue().length();
        }

        return size;
    }

}
