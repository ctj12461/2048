#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "tools.h"
#include <iostream>
#include <string>
#include "point.h"
#include "statement.h"

class menu
{
public:
	menu();
	int outputMainMenu();
	int outputDifficultyChoiceMenu();
	int outputSubMenu();
private:
	point MenuPoint;
	int outMenu(std::string arr[], int highest, int left, int right, int top);
};

#endif
