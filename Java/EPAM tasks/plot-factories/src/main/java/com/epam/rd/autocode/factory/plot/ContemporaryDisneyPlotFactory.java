package com.epam.rd.autocode.factory.plot;

public class ContemporaryDisneyPlotFactory implements PlotFactory {
    private final Character hero;
    private final EpicCrisis epicCrisis;
    private final Character funnyFriend;

    public ContemporaryDisneyPlotFactory(Character hero, EpicCrisis epicCrisis, Character funnyFriend) {
        this.hero = hero;
        this.epicCrisis = epicCrisis;
        this.funnyFriend = funnyFriend;
    }

    @Override
    public Plot plot() {
        return () -> "In the beginning, " + hero.name() +
                " feels a bit awkward and uncomfortable. But personal issue fades, when a big trouble comes - " +
                epicCrisis.name() + ". " + hero.name() +
                " stands up against it, but with no success at first. But then, by putting self together and with the help of friends, including spectacular, funny " +
                funnyFriend.name() + ", " + hero.name() +
                " restores the spirit, overcomes the crisis and gains gratitude and respect.";
    }
}
