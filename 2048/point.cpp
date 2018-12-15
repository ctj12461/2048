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

	tools::setPosition(X, Y);

}

void point::write(int cx, int cy, int num) {
#ifdef Linux
	cout << Colorstr;
#endif // Linux
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
#ifdef Linux
		cout << Colorstr;
#endif // Linux
		cout << str;

}

void point::write(int num,bool is_out_endl){
#ifdef Linux
	cout << Colorstr;
#endif // Linux

	cout << num;

	if (is_out_endl) {

		cout << endl;

	}
	
}

void point::write(std::string str){

	cout << str;
}

#ifdef Linux
//作用：设置输出的字体颜色
void point::setColor(color num) {
	switch (num)
	{
	case C_RED:
		Colorstr = "\033[0;31;40m";
		break;
	case C_GREEN:
		Colorstr = "\033[0;32;40m";
		break;
	case C_BLUE:
		Colorstr = "\033[0;34;40m";
		break;
	case C_YELLOW:
		Colorstr = "\033[0;33;40m";
		break;
	case C_CYAN:
		Colorstr = "\033[0;36;40m";
		break
	case C_PUPRLE:
		Colorstr = "\033[0;35;40m";
		break;
	case C_WHITE:
		Colorstr = "\033[0;37;40m";
		break;
	case C_BLACK:
		Colorstr = "\033[0;30;40m";
		break;
	case CI_RED:
		Colorstr = "\033[1;31;40m";
		break;
	case CI_GREEN:
		Colorstr = "\033[1;32;40m";
		break;
	case CI_BLUE:
		Colorstr = "\033[1;34;40m";
		break;
	case CI_YELLOW:
		Colorstr = "\033[1;33;40m";
		break;
	case CI_CYAN:
		Colorstr = "\033[1;36;40m";
		break;
	case CI_PUPRLE:
		Colorstr = "\033[1;35;40m";
		break;
	case CI_WHITE:
		Colorstr = "\033[1;30;40m";
		break;
	}
}

#endif

#ifdef Windows
//作用：设置输出的字体颜色
void point::setColor(color num) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(num));

}

#endif