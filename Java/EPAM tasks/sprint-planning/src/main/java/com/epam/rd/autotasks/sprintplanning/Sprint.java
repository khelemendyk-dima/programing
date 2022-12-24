package com.epam.rd.autotasks.sprintplanning;

import com.epam.rd.autotasks.sprintplanning.tickets.Bug;
import com.epam.rd.autotasks.sprintplanning.tickets.Ticket;
import com.epam.rd.autotasks.sprintplanning.tickets.UserStory;

import java.util.Arrays;

public class Sprint {
    private final int timeCapacity;
    private final int ticketsLimit;
    private final Ticket[] tickets;
    private int numOfTickets = 0;
    public Sprint(int capacity, int ticketsLimit) {
        this.timeCapacity = capacity;
        this.ticketsLimit = ticketsLimit;
        this.tickets = new Ticket[ticketsLimit];
    }

    private boolean isValid(Ticket ticket) {
        return ticket != null
                && !ticket.isCompleted()
                && (getTotalEstimate() + ticket.getEstimate() <= timeCapacity)
                && numOfTickets != ticketsLimit;
    }
    private boolean isDependencyInSprint(UserStory userStory) {
        if (userStory.getDependencies().length == 0) {
            return true;
        }
        if (numOfTickets == 0
                || userStory.getDependencies().length > numOfTickets) {
            return false;
        }
        for (int i = 0; i < numOfTickets; i++) {
            boolean isInSplit = false;
            for (int j = 0; j < userStory.getDependencies().length; j++) {
                if (tickets[i] == userStory.getDependencies()[j]) {
                    isInSplit = true;
                }
            }
            if (!isInSplit) {
                return  false;
            }
        }
        return true;
    }
    public boolean addUserStory(UserStory userStory) {
        if (isValid(userStory) && isDependencyInSprint(userStory)) {
            tickets[numOfTickets] = userStory;
            numOfTickets++;
            return true;
        }
        return false;
    }

    public boolean addBug(Bug bugReport) {
        if (isValid(bugReport)) {
            tickets[numOfTickets] = bugReport;
            numOfTickets++;
            return true;
        }
        return false;
    }

    public Ticket[] getTickets() {
        return Arrays.copyOf(tickets, numOfTickets);
    }

    public int getTotalEstimate() {
        int total = 0;
        for (int i = 0; i < numOfTickets; i++) {
            total += tickets[i].getEstimate();
        }
        return total;
    }
}

