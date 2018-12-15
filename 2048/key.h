#ifndef KEY_H
#define KEY_H

#include <iostream>
#include "square.h"
#include "menu.h"

class key
{
public:
	key(square& s, menu& m);
	~key();
	int chooseKey();
private:
	square& Square;
	menu& Menu;
	int chooseSubItem();
};

#endif // !KEY_H



