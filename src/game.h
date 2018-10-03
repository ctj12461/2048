#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include "menu.h"
#include "statement.h"
#include "square.h"

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

		int chooseKey();

		int chooseSubItem();

		void pause();

		void displayProgressBar(int x, int y, std::string str);

		void setPosition(int x, int y);

	private:

		square::difficulty Diff;

		menu GameMenu;

		square GameSquare;

		point GamePoint;

		int HighestScore;

};

#endif
