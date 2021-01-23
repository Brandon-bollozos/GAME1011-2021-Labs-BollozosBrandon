/*
* Brandon Gomez Bollozos - 101314522
* Advanced Programming GAME 1011 - Lab 1 - January 22 2021
* This program will
*/
#include <iostream>
#include <string>

using namespace std; 

class Achievement
{
private:
	string m_achievement, m_description;
	int m_score;
public:
	Achievement()
	{
		m_achievement = "N/A";
		m_description = "N/A";
		m_score = 0;
	}
	Achievement(string m_achievement, string m_description, int m_score)
	{
		this ->m_achievement = m_achievement;
		this ->m_description = m_description;
		this ->m_score = m_score;
	}
	void setAchievement(string m_achievement)
	{
		this->m_achievement = m_achievement;
	}
	void setDescription(string m_description)
	{
		this->m_description = m_description;
	}
	void setScore(int m_score)
	{
		this->m_score = m_score;
	}
	string getAchievement()
	{
		return m_achievement;
	}
	string getDescription()
	{
		return m_description;
	}
	int getScore()
	{
		return m_score;
	}
};

class Game
{
private:
	string m_game, m_publisher, m_developer;
	Achievement* m_pAchievements;
	size_t m_achieveSize;
public:
	Game()
	{
		m_game = "N/A";
		m_publisher = "N/A";
		m_developer = "N/A";
	}
	Game(string m_game, string m_publisher, string m_developer)
	{
		this->m_game = m_game;
		this->m_publisher = m_publisher;
		this->m_developer = m_developer;
	}
	void achievementStats(Achievement achievements, size_t m_achieveSize)
	{
		this->m_achieveSize = m_achieveSize;
		m_pAchievements = new Achievement[m_achieveSize];
		setAchievements(achievements);
	}
	string getTitle()
	{
		return m_game;
	}
	string getPublisher()
	{
		return m_publisher;
	}
	string getDeveloper()
	{
		return m_developer;
	}
	void setGames(string m_game)
	{
		this->m_game = m_game;
	}
	void setPublisher(string m_publisher)
	{
		this->m_publisher = m_publisher;
	}

	void setDeveloper(string m_developer)
	{
		this->m_developer = m_developer;
	}

	void setAchievements(Achievement achievements)
	{
		string achievementInfo;
		int score;
		for (size_t i = 0; i < m_achieveSize; i++)
		{
			cout << "Achievement number " << (i + 1) << ": ";
			getline(cin, achievementInfo);
			m_pAchievements[i].setAchievement(achievementInfo);
			cout << "Achievement Description: ";
			getline(cin, achievementInfo);
			m_pAchievements[i].setDescription(achievementInfo);
			cout << "Achievement score: ";
			cin >> score;
			cin.ignore();
			m_pAchievements[i].setScore(score);
			cout << endl << endl;
		}
	}
	void gameStats(Game* game, int choice)
	{
		cout << "Game: " << game[choice].getTitle() << endl;
		cout << "Publisher: " << game[choice].getPublisher() << endl;
		cout << "Developer: " << game[choice].getDeveloper() << endl << endl;
		game[choice].getAchieveGame();
	}
	void getAchieveGame()
	{
		for (size_t i = 0; i < m_achieveSize; i++)
		{
			cout << m_pAchievements[i].getAchievement() << endl;
			cout << m_pAchievements[i].getDescription() << endl;
			cout << m_pAchievements[i].getScore() << endl;
		}
	}
};

class Platform
{
private:
	string m_platform, m_manufacturer;
public:
	Platform(string m_platform, string m_manufacturer)
	{
		this->m_platform = m_platform;
		this->m_manufacturer = m_manufacturer;
	}
	string getPlatform()
	{
		return m_platform;
	}
	string getManu()
	{
		return m_manufacturer;
	}
};

Platform setPlatform();
void setGameInfo(Game* games, size_t gameSize);
size_t numberOfGames();
void seeStuff(Platform platform, Game* games, size_t gameSize);
int main()
{
	Platform platform = setPlatform();
	Game* games;
	size_t gameSize = numberOfGames();
	cout << endl << endl;
	games = new(nothrow)Game[gameSize];
	setGameInfo(games, gameSize);
	cout << endl << endl;
	seeStuff(platform, games, gameSize);
	cout << endl;
	return 0;
}// end main

void setGameInfo(Game* games, size_t gameSize)
{
	string nameOfGame, namePublisher, nameDeveloper;
	Achievement achievement;
	int numberOfAchievement;
	for (size_t i = 0; i < gameSize; i++)
	{
		cout << "Title of Game: ";
		getline(cin, nameOfGame);
		games[i].setGames(nameOfGame);
		cout << "Publisher Name: ";
		getline(cin, namePublisher);
		games[i].setPublisher(namePublisher);
		cout << "Developer Name: ";
		getline(cin, nameDeveloper);
		games[i].setDeveloper(nameDeveloper);
		cout << "Number Of Achievements: ";
		cin >> numberOfAchievement;
		cin.ignore();
		cout << endl << endl;
		games[i].achievementStats(achievement, numberOfAchievement);
	}
}

Platform setPlatform()
{
	string plat, manu;
	cout << "What Platform are your games on? ";
	getline(cin, plat);
	cout << "Who is the manufactuer? ";
	getline(cin, manu);
	Platform platform(plat, manu);
	return platform;
}

size_t numberOfGames()
{
	size_t number;
	cout << "How many games are on there? ";
	cin >> number;
	cin.ignore();
	return number;
}

void seeStuff(Platform platform, Game* games, size_t gameSize)
{
	int choice;
	cout << "Platform: " << platform.getPlatform() << endl;
	cout << "Manufacturer: " << platform.getManu() << endl << endl << endl;
	cout << "From the list below, please choose which \ngame you want to see your stats on?" << endl << endl;
	for (size_t i = 0; i < gameSize; i++)
	{
		cout << "PRESS " << (i + 1) << " for " << games[i].getTitle() << endl;
	}
	cin >> choice;
	games[choice].getAchieveGame();
}

