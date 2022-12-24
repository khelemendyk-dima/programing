package com.epam.rd.autocode.observer.git;

import java.util.ArrayList;
import java.util.List;

public class WebHookObserver implements WebHook {
    private final Branch observable;
    private final List<Event> events = new ArrayList<>();
    private Event.Type type;

    public WebHookObserver(Branch target) {
        this.observable = target;
    }

    public void setType(Event.Type type) {
        this.type = type;
    }

    @Override
    public String branch() {
        return observable.toString();
    }

    @Override
    public Event.Type type() {
        return this.type;
    }

    @Override
    public List<Event> caughtEvents() {
        return events;
    }

    @Override
    public void onEvent(Event event) {
        events.add(event);
    }
}
