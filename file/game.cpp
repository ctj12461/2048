
#include "stdafx.h"
#include "game.h"

using namespace std;

game::game()
:game_menu(), game_point(), game_square(square::DIFFICULTY_INIT), highest_score(0), diff(square::DIFFICULTY_INIT)
{
}

void game::run(){
	
	srand(static_cast<unsigned int>(time(NULL)));

	welcome();

	first();

	over();

}

void game::welcome()
{
	
	game_point.set_color(point::CI_CYAN);

	cout << endl;
	cout << endl;	
	cout << endl;
	cout << endl;
	cout << "      ###      ###       ##       ###        " << endl;
	cout << "     #   #    #   #     # #      #   #       " << endl;
	cout << "          #  #     #   #  #      #   #       " << endl;
	cout << "          #  #     #  #   #       ###        " << endl;
	cout << "         #   #     # #########   #   #       " << endl;
	cout << "        #    #     #      #     #     #      " << endl;
	cout << "       #      #   #       #      #   #       " << endl;
	cout << "     ######    ###        #       ###        " << endl;
	cout << endl;
	cout << endl;
	cout << "             Welcome to 2048!" << endl;
	cout << "             Version " << VERSION << endl;

	autoDisplay(3, 17, "Loading...");

	game_point.set_color(point::C_WHITE);

	cin.get();

}

void game::first(){

	int item_index = 0;
	
	do {

		item_index = game_menu.out_first_menu();

		switch (item_index) {

			case ITEM_NEW_GAME: {

				second();

				break;

			}

			case ITEM_HIGHEST_SCORE: {

				display_score();

				break;

			}

			case ITEM_ABOUT: {

				display_about();

				break;

			}

		}

	} while (item_index != ITEM_QUIT_FIRST);

}

void game::second(){

	int item_index = 0;

	int msg = 0;

	do {

		item_index = game_menu.out_second_menu();

		if (item_index == ITEM_QUIT_SECOND) {
			return;
		}

		if (item_index == ITEM_EASY) {
			diff = square::DIFFICULTY_EASY;
		}else if (item_index == ITEM_MIDDLE) {
			diff = square::DIFFICULTY_MIDDLE;
		}else{
			diff = square::DIFFICULTY_DIFFICULT;
		}

		game_square.SetDifficulty(diff);

		msg = start_game();

	} while (msg == RE_START);

}

int game::sub(){

	int index = game_menu.out_sub_menu();

	return index;
}

void game::game_over(int msg){

	int mark = game_square.get_mark();

	system("cls");

	game_point.write(20, 0, "2048");

	if (msg == WIN) {

		game_point.write(17, 3, "YOU WIN!!!");
		cout << endl;
		cout << "           " << setw(18) << left << "Score" << mark << endl;
		cout << "           " << setw(18) << left << "Highest Score" << highest_score << endl;
		MessageBox(NULL, TEXT("YOU WIN!!!"), TEXT("Message"), MB_OK + MB_ICONINFORMATION);
			
	}
	else {

		game_point.write(18, 3, "YOU LOST!!!");
		cout << endl;
		cout << "           " << setw(18) << left << "Score" << mark << endl;
		cout << "           " << setw(18) << left << "Highest Score" << highest_score << endl;
		MessageBox(NULL, TEXT("YOU LOST!!!"), TEXT("Message"), MB_OK + MB_ICONINFORMATION);

	}

	pause();
	
}

void game::update_highest_score(){

	int mark = game_square.get_mark();

	if (highest_score < mark) {

		highest_score = mark;

	}

}

int game::start_game(){

	string ch;

	int msg = 0;

	game_square.Clear();

	msg = game_run();

	update_highest_score();

	if (msg == WIN || msg == LOST) {

		game_over(msg);

	}

	return msg;

}

int game::game_run(){

	string ch = "";

	int msg = 0;

	do {

		if (msg != CONTINUE) {

			game_square.update();
		
		}

		game_square.SetDifficulty(diff);

		game_square.updatemap();

		msg = ChooseKey();

	} while (msg == RUNNING || msg == CONTINUE);

	return msg;
}

void game::display_score(){

	system("cls");

	game_point.write(20, 0, "2048");

	cout << endl << "   Highest score : " << highest_score << endl;

	pause();

}

void game::display_about(){

	system("cls");
	game_point.write(20, 0, "2048");
	cout << endl;
	cout << "Press W S A D to move square." << endl;
	cout << "Press P to pause." << endl;
	cout << endl;
	cout << "                  2048" << endl;
	cout << endl;
	cout << endl;
	cout << "                 By Ctj" << endl;
	cout << "             Version " << VERSION << endl;
	cout << "                 " << DATE_ << endl;
	cout << endl;

	pause();

}

void game::over(){

	system("cls");

	cout << "Thank you for playing 2048!!!" << endl;

	pause();

}

int game::ChooseKey()
{
	string ch = "";
	int msg = 0;
	bool isExit = false;

	do {

		cin >> ch;

		if (ch[0] == 'W' || ch[0] == 'w') {

			game_square.changesquare(KEY_UP);			
			isExit = true;

		}else if (ch[0] == 'S' || ch[0] == 's') {

			game_square.changesquare(KEY_DOWN);		
			isExit = true;

		}else if (ch[0] == 'A' || ch[0] == 'a') {

			game_square.changesquare(KEY_LEFT);		
			isExit = true;

		}else if (ch[0] == 'D' || ch[0] == 'd') {

			game_square.changesquare(KEY_RIGHT);		
			isExit = true;

		}else if (ch[0] == 'P' || ch[0] == 'p') {

			msg = ChooseSubItem();
			break;

		}

		if (isExit) {
			msg = game_square.isover();
			break;
		}

	} while (true);

	return msg;

}

int game::ChooseSubItem()
{
	int index = 0, msg = 0;

	do {

		index = sub();

		if (index == CONTINUE) {

			game_point.write(0, 44, "Continue");

			msg = CONTINUE;

			break;

		}
		else if (index == RE_START) {

			msg = RE_START;

			break;

		}
		else if (index == QUIT) {

			msg = QUIT;

			break;

		}

	} while (true);

	return msg;
}

inline void game::pause()
{
	cin.ignore();
	cin.get();
}

void game::autoDisplay(int x, int y, std::string str)
{
	setPosition(x, y);

	int Space = 5;
	

	cout << "                          " << "[ " << str << " ]";

	for (int i = 1; i <= 100; i++)
	{
		cout << "\r";
		for (int j = x; j <= x; j++) { cout << " "; }
		cout << "[ ";
		game_point.set_color(point::CI_CYAN);	//������ɫ
		cout << i << "%";
		game_point.set_color(point::C_WHITE);	//���ð�ɫ
		cout << " ]";
		game_point.set_color(point::CI_CYAN);	//������ɫ
		for (int j = Space; j < i; j += Space) { cout << "#"; }
		if (i % Space == 0) { cout << "#" << flush; }
		game_point.set_color(point::C_WHITE);	//���ð�ɫ
		Sleep(50);
	}
	cout << endl;
}

void game::setPosition(int x, int y)
{
	HANDLE winHandle;//���
	COORD pos = { static_cast<short>(x),static_cast<short>(y) };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ�� 
	SetConsoleCursorPosition(winHandle, pos);
}