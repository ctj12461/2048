
#include "stdafx.h"
#include "game.h"

using namespace std;

//

game::game()
:GameMenu(), GamePoint(), GameSquare(square::DIFFICULTY_INIT), HighestScore(0), Diff(square::DIFFICULTY_INIT)
{
}

void game::run(){
	
	srand(static_cast<unsigned int>(time(NULL)));

	welcome();

	displayMainMenu();

	over();

}

void game::welcome()
{
	
	GamePoint.setColor(point::CI_CYAN);

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

	displayProgressBar(3, 17, "Loading...");

	GamePoint.setColor(point::C_WHITE);

	cin.get();

}

void game::displayMainMenu(){

	int item_index = 0;
	
	do {

		item_index = GameMenu.outputMainMenu();

		switch (item_index) {

			case ITEM_NEW_GAME: {

				displayDifficultyChoiceMenu();

				break;

			}

			case ITEM_HIGHEST_SCORE: {

				displayScore();

				break;

			}

			case ITEM_ABOUT: {

				displayAbout();

				break;

			}

		}

	} while (item_index != ITEM_QUIT_FIRST);

}

void game::displayDifficultyChoiceMenu(){

	int item_index = 0;

	int msg = 0;

	do {

		item_index = GameMenu.outputDifficultyChoiceMenu();

		if (item_index == ITEM_QUIT_SECOND) {
			return;
		}

		if (item_index == ITEM_EASY) {
			Diff = square::DIFFICULTY_EASY;
		} else if (item_index == ITEM_MIDDLE) {
			Diff = square::DIFFICULTY_MIDDLE;
		} else if (item_index == ITEM_DIFFICULT){
			Diff = square::DIFFICULTY_DIFFICULT;
		} else {
			Diff = square::DIFFICULTY_INFINITE;
		}

		GameSquare.setDifficulty(Diff);

		msg = startGame();

	} while (msg == RE_START);

}

int game::displaySubMenu(){

	int index = GameMenu.outputSubMenu();

	return index;
}

void game::displayMessage(int msg){

	int mark = GameSquare.getMark();

	system("cls");

	GamePoint.write(20, 0, "2048");

	if (msg == WIN) {

		GamePoint.write(17, 3, "YOU WIN!!!");
		cout << endl;
		cout << "           " << setw(18) << left << "Score" << mark << endl;
		cout << "           " << setw(18) << left << "Highest Score" << HighestScore << endl;
		MessageBox(NULL, TEXT("YOU WIN!!!"), TEXT("Message"), MB_OK + MB_ICONINFORMATION);
			
	}
	else {

		GamePoint.write(18, 3, "YOU LOST!!!");
		cout << endl;
		cout << "           " << setw(18) << left << "Score" << mark << endl;
		cout << "           " << setw(18) << left << "Highest Score" << HighestScore << endl;
		MessageBox(NULL, TEXT("YOU LOST!!!"), TEXT("Message"), MB_OK + MB_ICONINFORMATION);

	}

	pause();
	
}

void game::updateHighestScore(){

	int mark = GameSquare.getMark();

	if (HighestScore < mark) {

		HighestScore = mark;

	}

}

int game::startGame(){

	string ch;

	int msg = 0;

	GameSquare.clear();

	msg = gameRun();

	if (msg == WIN || msg == LOST) {

		displayMessage(msg);

	}

	return msg;

}

int game::gameRun(){

	string ch = "";

	int msg = 0;

	do {

		if (msg != CONTINUE) {

			GameSquare.update();
			
		}

		GameSquare.setDifficulty(Diff);

		GameSquare.updateMap();

		updateHighestScore();

		msg = chooseKey();

	} while (msg == RUNNING || msg == CONTINUE);

	return msg;
}

void game::displayScore(){

	system("cls");

	GamePoint.write(20, 0, "2048");

	cout << endl << "   Highest score : " << HighestScore << endl;

	pause();

}

void game::displayAbout(){

	system("cls");
	GamePoint.write(20, 0, "2048");
	cout << endl;
	cout << "Press W S A D to move square." << endl;
	cout << "Press P to pause." << endl;
	cout << endl;
	cout << "                  2048" << endl;
	cout << endl;
	cout << endl;
	cout << "                 By Ctj" << endl;
	cout << "             Version " << VERSION << endl;
	cout << "               " << DATE_ << endl;
	cout << endl;

	pause();

}

void game::over(){

	system("cls");

	cout << "Thank you for playing 2048!!!" << endl;

	pause();

}

int game::chooseKey()
{
	string ch = "";
	int msg = 0;
	bool isExit = false;

	do {

		cin >> ch;

		if (ch[0] == 'W' || ch[0] == 'w') {

			GameSquare.changeSquare(KEY_UP);			
			isExit = true;

		}else if (ch[0] == 'S' || ch[0] == 's') {

			GameSquare.changeSquare(KEY_DOWN);		
			isExit = true;

		}else if (ch[0] == 'A' || ch[0] == 'a') {

			GameSquare.changeSquare(KEY_LEFT);		
			isExit = true;

		}else if (ch[0] == 'D' || ch[0] == 'd') {

			GameSquare.changeSquare(KEY_RIGHT);		
			isExit = true;

		}else if (ch[0] == 'P' || ch[0] == 'p') {

			msg = chooseSubItem();
			break;

		}

		if (isExit) {
			msg = GameSquare.isOver();
			break;
		}

	} while (true);

	return msg;

}

int game::chooseSubItem()
{
	int index = 0, msg = 0;

	do {

		index = displaySubMenu();

		if (index == CONTINUE) {

			GamePoint.write(0, 44, "Continue");

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

void game::displayProgressBar(int x, int y, std::string str)
{
	setPosition(x, y);

	int Space = 5;
	

	cout << "                          " << "[ " << str << " ]";

	for (int i = 1; i <= 100; i++)
	{
		cout << "\r";
		for (int j = x; j <= x; j++) { cout << " "; }
		cout << "[ ";
		GamePoint.setColor(point::CI_CYAN);	//设置青色
		cout << i << "%";
		GamePoint.setColor(point::C_WHITE);	//设置白色
		cout << " ]";
		GamePoint.setColor(point::CI_CYAN);	//设置青色
		for (int j = Space; j < i; j += Space) { cout << "#"; }
		if (i % Space == 0) { cout << "#" << flush; }
		GamePoint.setColor(point::C_WHITE);	//设置白色
		Sleep(50);
	}
	cout << endl;
}

void game::setPosition(int x, int y)
{
	HANDLE winHandle;//句柄
	COORD pos = { static_cast<short>(x),static_cast<short>(y) };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);
}