package com.epam.rd.autocode.decorator;

import java.util.AbstractList;
import java.util.List;

public abstract class AbstractDecorator extends AbstractList<String> {
    private final List<String> sourceList;

    public AbstractDecorator(List<String> sourceList) {
        this.sourceList = sourceList;
    }

    protected List<String> getList() {
        return this.sourceList;
    }

    public abstract int size();

    public abstract String get(int index);
}
