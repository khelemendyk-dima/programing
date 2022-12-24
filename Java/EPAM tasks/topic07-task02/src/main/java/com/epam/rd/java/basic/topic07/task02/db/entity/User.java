package com.epam.rd.java.basic.topic07.task02.db.entity;

public class User {

	private int id;

	private String login;

	public User(int id, String login) {
		this.id = id;
		this.login = login;
	}
	public int getId() {
		return id;
	}

	public String getLogin() {
		return login;
	}

	public static User createUser(String login) {
		return new User(0, login);
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null || this.getClass() != obj.getClass())
			return false;
		User other = (User)obj;
		return this.id == other.id && this.login.equals(other.login);
	}

	@Override
	public String toString() {
		return this.getLogin();
	}
}