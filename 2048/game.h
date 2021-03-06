#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include "menu.h"
#include "statement.h"
#include "square.h"
#include "key.h"
#include "tools.h"

class game
{
public:
	game();
	void run();
	void welcome();
	void displayMainMenu();
	void displayDifficultyChoiceMenu();
	int displaySubMenu();
	void displayMessage(int msg);
	void updateHighestScore();
	int startGame();
	int gameRun();
	void displayScore();
	void displayAbout();
	void over();
	void displayProgressBar(int x, int y, std::string str);
private:
	square::difficulty Diff;
	menu GameMenu;
	square GameSquare;
	point GamePoint;
	key GameKeyChooser;
	int HighestScore;

};

#endif
