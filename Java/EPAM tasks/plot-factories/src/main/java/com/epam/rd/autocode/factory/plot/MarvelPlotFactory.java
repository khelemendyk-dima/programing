package com.epam.rd.autocode.factory.plot;

import java.util.StringJoiner;

public class MarvelPlotFactory implements PlotFactory {
    private final Character[] heroes;
    private final EpicCrisis epicCrisis;
    private final Character villain;

    public MarvelPlotFactory(Character[] heroes, EpicCrisis epicCrisis, Character villain) {
        this.heroes = heroes;
        this.epicCrisis = epicCrisis;
        this.villain = villain;
    }

    @Override
    public Plot plot() {
        if (heroes.length == 1) {
            return () -> epicCrisis.name() + " threatens the world. But the brave " +
                    heroes[0].name() + " is on guard. So, no way that intrigues of " + villain.name() +
                    " will bend the willpower of the inflexible hero.";
        }
        String braveHeroes = getBraveHeroes();
        return () -> epicCrisis.name() + " threatens the world. But the brave " +
                braveHeroes + " on guard. So, no way that intrigues of " +
                villain.name() + " will bend the willpower of inflexible heroes.";
    }

    private String getBraveHeroes() {
        StringJoiner sj = new StringJoiner(", the brave ");
        for (int i = 0; i < heroes.length - 1; i++) {
            sj.add(heroes[i].name());
        }
        String lastHero = " and the brave " + heroes[heroes.length - 1].name() + " are";
        return sj + lastHero;
    }
}
