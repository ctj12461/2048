#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include "statement.h"
#include "point.h"

class square
{
	
	public:
		
		enum difficulty { 
			DIFFICULTY_EASY = 2048, DIFFICULTY_MIDDLE = 8192, DIFFICULTY_DIFFICULT = 65536, 
			DIFFICULTY_INFINITE = -1, DIFFICULTY_INIT = 0,
		};

		square();

		square(difficulty diff);

		void setDifficulty(difficulty diff);
		
		void changeSquare(int action);
		
		int isOver();
		
		void update();

		int getMark();

		void updateMap();

		void clear();
		
	private:
		
		int GameSquare[4][4];
		
		int Size;

		difficulty Difficulty;

		int Mark;

		point OutPoint;

		void updateMark();
		
		void arrMove(int action);
		
};

#endif

