#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <Windows.h>
#include <string>

class point
{
	public:

		enum color {
			C_RED = 0x0004, C_GREEN = 0x0002, C_BLUE = 0x0001, C_YELLOW = 0x0006, 
			C_CYAN = 0x0003, C_PURPLE = 0x0005, C_WHITE = 0x0007, C_BLACK = 0x0000,		//无高亮
			
			CI_RED = 0x000C,CI_GREEN = 0x000A, CI_BLUE = 0x0009, CI_YELLOW = 0x000E,	//有高亮
			CI_CYAN = 0x000B, CI_PURPLE = 0x000D
		};
		
		point();

		~point();

		void write(int cx, int cy, int num);

		void write(int cx, int cy, std::string str);

		void write(int num,bool is_out_endl);

		void write(std::string str);

		void setColor(color num);

	private:

		int X;

		int Y;

		void gotoPoint();

		void setPoint(int cx, int cy);

};

#endif

