package com.epam.rd.autocode.decorator;

import java.util.List;

public class EvenIndexElementsDecorator extends AbstractDecorator {

    public EvenIndexElementsDecorator(List<String> sourceList) {
        super(sourceList);
    }

    @Override
    public int size() {
        return (getList().size() + 1) / 2;
    }

    @Override
    public String get(int index) {
        return getList().get(index * 2);
    }
}
