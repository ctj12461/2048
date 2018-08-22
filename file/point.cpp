#include "stdafx.h"
#include "point.h"

using namespace std;

point::point()
	:x(0),y(0)
{
}

point::~point()
{
}

void point::setpoint(int cx, int cy) {

	x = cx;

	y = cy;

}

void point::gotopoint(){

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD c = { static_cast<short int>(x), static_cast<short int>(y) };

	SetConsoleCursorPosition(hOut, c);

}

void point::write(int cx, int cy, int num) {

	if (num == 0) {

		setpoint(cx, cy);

		gotopoint();

		cout << "";

	}
	else if (num > 0 && num < 10) {

		setpoint(cx, cy);

		gotopoint();

		cout << num;

	}
	else if (num >= 10 && num < 100) {

		setpoint(cx - 1, cy);

		gotopoint();

		cout << num;

	}
	else if (num >= 100 && num < 1000) {

		setpoint(cx - 1, cy);

		gotopoint();

		cout << num;

	}
	else if (num >= 1000 && num < 10000) {

		setpoint(cx - 2, cy);

		gotopoint();

		cout << num;

	}

}

void point::write(int cx, int cy, std::string str){

		setpoint(cx, cy);

		gotopoint();

		cout << str;

}

void point::write(int num,bool is_out_endl){

	cout << num;

	if (is_out_endl) {

		cout << endl;

	}
	
}

void point::write(std::string str){

	cout << str;
}

//作用：设置输出的字体颜色
void point::set_color(int num) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);

}