package com.epam.rd.java.basic.topic07.task01.db.entity;

public class Team {

	private final int id;
	private final String name;

	public Team(int id, String name) {
		this.id = id;
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public static Team createTeam(String name) {
		return new Team(0, name);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null || this.getClass() != obj.getClass())
			return false;
		Team other = (Team)obj;
		return this.id == other.id && this.name.equals(other.name);

	}

	@Override
	public String toString() {
		return getName();
	}
}