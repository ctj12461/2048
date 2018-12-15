#include "stdafx.h"
#include "tools.h"

using namespace std;

void tools::pause()
{
	cin.ignore();
	cin.get();
}

#ifdef Linux

void tools::clear(){
	system("clear");
}

void tools::setPosition(int x, int y){

}

void tools::resize(int col, int row){

}

#endif // Linux

#ifdef Windows

void tools::clear(){
	system("cls");
}

void tools::setPosition(int x, int y){
	HANDLE winHandle;//句柄
	COORD pos = { static_cast<short>(x),static_cast<short>(y) };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);
}

void tools::resize(int col, int row) {
	stringstream s;
	string c, r;
	s << col;
	s >> c;
	s << row;
	s >> r;
	system(("mode con cols=" + c + " lines=" + r).c_str());
}
#endif // Windows



tools::tools()
{
}


tools::~tools()
{
}
