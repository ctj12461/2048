#include "stdafx.h"
#include "key.h"

using namespace std;

key::key(square& s, menu& m)
	:
	Square(s),
	Menu(m)
{
}

key::~key()
{
}

int key::chooseKey(){
	string ch = "";
	int msg = 0;
	bool isExit = false;

	do {

		cin >> ch;

		if (ch[0] == 'W' || ch[0] == 'w') {

			Square.changeSquare(KEY_UP);
			isExit = true;

		}
		else if (ch[0] == 'S' || ch[0] == 's') {

			Square.changeSquare(KEY_DOWN);
			isExit = true;

		}
		else if (ch[0] == 'A' || ch[0] == 'a') {

			Square.changeSquare(KEY_LEFT);
			isExit = true;

		}
		else if (ch[0] == 'D' || ch[0] == 'd') {

			Square.changeSquare(KEY_RIGHT);
			isExit = true;

		}
		else if (ch[0] == 'P' || ch[0] == 'p') {

			msg = chooseSubItem();
			break;

		}

		if (isExit) {
			msg = Square.isOver();
			break;
		}

	} while (true);

	return msg;
}

int key::chooseSubItem(){
	int index = 0, msg = 0;
	do {
		index = Menu.outputSubMenu();
		if (index == CONTINUE) {
			msg = CONTINUE;
			break;
		} else if (index == RE_START) {
			msg = RE_START;
			break;
		} else if (index == QUIT) {
			msg = QUIT;
			break;
		}
	} while (true);
	return msg;
}
