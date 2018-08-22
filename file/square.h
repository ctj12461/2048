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
			DIFFICULTY_EASY = 2048, DIFFICULTY_MIDDLE = 8192, DIFFICULTY_DIFFICULT = 65536, DIFFICULTY_INIT = 0
		};

		square();

		square(difficulty diff);

		void SetDifficulty(difficulty diff);
		
		void changesquare(int action);
		
		int isover();
		
		void update();

		int get_mark();

		void updatemap();

		void Clear();
		
	protected:
		
		int gamesquare[4][4];
		
		int size;
		
		int max;

		difficulty Difficulty;

		int mark;

		point outpoint;
		
		void arrmove(int action);
		
};

#endif

