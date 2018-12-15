#ifndef TOOLS_H
#define TOOLS_H

#include "statement.h"

#ifdef Linux

#endif // Linux

#ifdef Windows
#include <Windows.h>
#endif // Windows

#include <iostream>
#include <cstdlib>
#include <sstream>

class tools
{
public:
	static void pause();
	static void clear();
	static void setPosition(int x, int y);
	static void resize(int col, int row);
private:
	tools();
	~tools();
};

#endif // !TOOLS_H



