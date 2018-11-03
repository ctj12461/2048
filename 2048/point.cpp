#include "stdafx.h"
#include "point.h"

using namespace std;

point::point()
	:X(0),Y(0)
{
}

point::~point()
{
}

void point::setPoint(int cx, int cy) {

	X = cx;

	Y = cy;

}

void point::gotoPoint(){

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD c = { static_cast<short int>(X), static_cast<short int>(Y) };

	SetConsoleCursorPosition(hOut, c);

}

void point::write(int cx, int cy, int num) {

	if (num == 0) {

		setPoint(cx, cy);

		gotoPoint();

		cout << "";

	}
	else if (num > 0 && num < 10) {

		setPoint(cx, cy);

		gotoPoint();

		cout << num;

	}
	else if (num >= 10 && num < 100) {

		setPoint(cx - 1, cy);

		gotoPoint();

		cout << num;

	}
	else if (num >= 100 && num < 1000) {

		setPoint(cx - 1, cy);

		gotoPoint();

		cout << num;

	}
	else if (num >= 1000 && num < 10000) {

		setPoint(cx - 2, cy);

		gotoPoint();

		cout << num;

	}

}

void point::write(int cx, int cy, std::string str){

		setPoint(cx, cy);

		gotoPoint();

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
void point::setColor(color num) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(num));

}