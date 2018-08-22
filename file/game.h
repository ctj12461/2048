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

		void first();

		void second();

		int sub();

		void game_over(int msg);

		void update_highest_score();

		int start_game();

		int game_run();

		void display_score();

		void display_about();

		void over();

		int ChooseKey();

		int ChooseSubItem();

	protected:

		square::difficulty diff;

		menu game_menu;

		square game_square;

		point game_point;

		int highest_score;

};

#endif
