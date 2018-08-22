#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <Windows.h>
#include <string>

class point
{
	public:

		point();

		~point();

		void write(int cx, int cy, int num);

		void write(int cx, int cy, std::string str);

		void write(int num,bool is_out_endl);

		void write(std::string str);

		void set_color(int num);

	private:

		int x;

		int y;

		void gotopoint();

		void setpoint(int cx, int cy);

};

#endif

