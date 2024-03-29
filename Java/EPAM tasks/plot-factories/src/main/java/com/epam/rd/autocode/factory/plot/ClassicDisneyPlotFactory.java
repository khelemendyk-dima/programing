package com.epam.rd.autocode.factory.plot;

public class ClassicDisneyPlotFactory implements PlotFactory {
    private final Character hero;
    private final Character beloved;
    private final Character villain;

    public ClassicDisneyPlotFactory(Character hero, Character beloved, Character villain) {
        this.hero = hero;
        this.beloved = beloved;
        this.villain = villain;
    }
    @Override
    public Plot plot() {
        return () -> hero.name() + " is young and adorable. " + hero.name() +
                " and " + beloved.name() + " love each other. " +  villain.name() +
                " interferes with their happiness, but loses in the end.";
    }
}
