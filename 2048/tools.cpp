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
	auto sx = to_string(x);
	auto sy = to_string(y);
	cout << "\033[" + sy + ";" + sx + "H";
}

void tools::resize(int col, int row){
	
}

void tools::sleepFor(int time){
	sleep(time / 1000);
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

void tools::sleepFor(size_t time) {
	Sleep(time);
}

#endif // Windows



tools::tools()
{
}


tools::~tools()
{
}
