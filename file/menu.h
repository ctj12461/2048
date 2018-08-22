#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <Windows.h>
#include <iostream>
#include <string>
#include "point.h"
#include "statement.h"

class menu
{
	public:

		menu();

		int out_first_menu();

		int out_second_menu();

		int out_sub_menu();

	protected:

		point menupoint;

		int out_menu(std::string arr[], int highest, int left, int right, int top);
};

#endif
