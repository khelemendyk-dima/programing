package com.epam.rd.java.basic.topic07.task02.db;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

import com.epam.rd.java.basic.topic07.task02.db.entity.*;

import static com.epam.rd.java.basic.topic07.task02.Constants.SETTINGS_FILE;

public class DBManager {

	private static DBManager instance = null;
	public static final String CONNECTION_URL = getConnectionURL();
	public static final String GET_ALL_USERS = "SELECT * FROM users";
	public static final String GET_ALL_TEAMS = "SELECT * FROM teams";
	public static final String INSERT_USER  = "INSERT INTO users VALUES(DEFAULT,?)";
	public static final String INSERT_TEAM  = "INSERT INTO teams VALUES(DEFAULT,?)";
	public static final String GET_USER  = "SELECT * FROM users WHERE login = ?";
	public static final String GET_TEAM  = "SELECT * FROM teams WHERE name = ?";
	public static final String DELETE_USER  = "DELETE FROM users WHERE id = ?";
	public static final String DELETE_TEAM  = "DELETE FROM teams WHERE name = ?";
	public static final String UPDATE_TEAM  = "UPDATE teams SET name = ? WHERE name = ?";
	public static final String SET_TEAMS_FOR_USER  = "INSERT INTO users_teams VALUES((SELECT id FROM users WHERE login = ?),(SELECT id FROM teams WHERE name = ?))";
	public static final String GET_USER_TEAMS  = "SELECT * FROM teams t JOIN users_teams ut ON t.id = ut.team_id JOIN users u ON ut.user_id = u.id WHERE u.login = ?";
	public static final String GET_TEAM_USERS  = "SELECT * FROM users u JOIN users_teams ut ON u.id = ut.team_id JOIN teams t ON ut.user_id = t.id WHERE t.name = ?";

	public static synchronized DBManager getInstance() {//
		if (instance == null)
			instance = new DBManager();
		return instance;
	}

	public List<User> findAllUsers() throws DBException {
		List<User> allUsers = new ArrayList<>();
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 Statement statement = connection.createStatement();
			 ResultSet resultSet = statement.executeQuery(GET_ALL_USERS)) {
			while (resultSet.next()) {
				String login = resultSet.getString("login");
				allUsers.add(User.createUser(login));
			}
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return allUsers;
	}

	public boolean insertUser(User user) throws DBException {
		boolean isInserted;
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 PreparedStatement pStatement = connection.prepareStatement(INSERT_USER)) {
			pStatement.setString(1, user.getLogin());
			isInserted = pStatement.execute();
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return isInserted;
	}

	public boolean deleteUsers(User... users) throws DBException {
		return false;
	}

	public User getUser(String login) throws DBException {
		User user;
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 PreparedStatement pStatement = connection.prepareStatement(GET_USER)) {
			pStatement.setString(1, login);
			ResultSet resultSet = pStatement.executeQuery();
			resultSet.next();
			int id = resultSet.getInt("id");
			user = new User(id, login);
			resultSet.close();
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return user;
	}

	public Team getTeam(String name) throws DBException {
		Team team;
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 PreparedStatement pStatement = connection.prepareStatement(GET_TEAM)) {
			pStatement.setString(1, name);
			ResultSet resultSet = pStatement.executeQuery();
			resultSet.next();
			int id = resultSet.getInt("id");
			team = new Team(id, name);
			resultSet.close();
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return team;
	}

	public List<Team> findAllTeams() throws DBException {
		List<Team> allTeams = new ArrayList<>();
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 Statement statement = connection.createStatement();
			 ResultSet resultSet = statement.executeQuery(GET_ALL_TEAMS)) {
			while (resultSet.next()) {
				String name = resultSet.getString("name");
				allTeams.add(Team.createTeam(name));
			}
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return allTeams;
	}

	public boolean insertTeam(Team team) throws DBException {
		boolean isInserted;
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 PreparedStatement pStatement = connection.prepareStatement(INSERT_TEAM)) {
			pStatement.setString(1, team.getName());
			isInserted = pStatement.execute();
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return isInserted;
	}

	public boolean setTeamsForUser(User user, Team... teams) throws DBException {
		boolean isSetted = false;
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);) {
			connection.setAutoCommit(false);
			try (PreparedStatement pStatement = connection.prepareStatement(SET_TEAMS_FOR_USER)) {
				pStatement.setString(1, user.getLogin());
				for (Team team : teams) {
					pStatement.setString(2, team.getName());
					isSetted = pStatement.execute();
				}
				connection.commit();
			} catch (SQLException e) {
				connection.rollback();
				e.printStackTrace();
				throw new DBException();
			}
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}

		return isSetted;
	}

	public List<Team> getUserTeams(User user) throws DBException {
		List<Team> userTeams = new ArrayList<>();
		try (Connection connection = DriverManager.getConnection(CONNECTION_URL);
			 PreparedStatement pStatement = connection.prepareStatement(GET_USER_TEAMS);) {
			pStatement.setString(1, user.getLogin());
			ResultSet resultSet = pStatement.executeQuery();
			while (resultSet.next()) {
				String name = resultSet.getString(2);
				userTeams.add(Team.createTeam(name));
			}
		} catch (SQLException e) {
			e.printStackTrace();
			throw new DBException();
		}
		return userTeams;
	}

	public boolean deleteTeam(Team team) throws DBException {
		return false;
	}

	public boolean updateTeam(Team team) throws DBException {
		return false;
	}

	private static String getConnectionURL() {
		Map<String, String> map = new HashMap<>();
		try (Stream<String> lines = Files.lines(Paths.get(SETTINGS_FILE))) {
			lines.filter(line -> line.contains("connection.url"))
					.forEach(line -> {
						String[] keyValuePair = line.split("=", 2);
						String key = keyValuePair[0];
						String value = keyValuePair[1];
						map.put(key, value);
					});

		} catch (IOException e) {
			e.printStackTrace();
		}
		return map.get("connection.url");
	}
}
