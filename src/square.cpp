#include "stdafx.h"
#include "square.h"


using namespace std;

//游戏算法部分 
#define COL 4
#define ROW 4

square::square()
:Size(0),Mark(0),Difficulty(DIFFICULTY_INIT),OutPoint()
{
	clear();
	
}

square::square(difficulty diff)
:Difficulty(diff), Size(0), Mark(0), OutPoint()
{
	clear();
}

void square::setDifficulty(difficulty diff)
{
	Difficulty = diff;
}

void square::changeSquare(int action){
	
	arrMove(action);

}
		
int square::isOver(){
	
	int diffNum = static_cast<int>(Difficulty);

	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (GameSquare[i][j] == diffNum)
			{
				return WIN;
			}
		}
	}

	//横向检查
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL - 1; ++j)
		{
			if (!GameSquare[i][j] || (GameSquare[i][j] == GameSquare[i][j + 1]))
			{
				return RUNNING;
			}
		}
	}

	//纵向检查
	for (int j = 0; j< COL; ++j)
	{
		for (int i = 0; i < ROW - 1; ++i)
		{
			if (!GameSquare[i][j] || (GameSquare[i][j] == GameSquare[i + 1][j]))
			{
				return RUNNING;
				break;
			}
		}
	}

	//不符合上述两种状况，游戏结束
	return LOST;
	
}
		
void square::update(){
	
	int x = -1;

	int y = -1;

	int times = 0;

	int maxTimes = ROW * COL;

	//三分之二的概率生成2，三分之一的概率生成4

	int whitch = rand() % 3;

	do

	{

		x = rand() % ROW;

		y = rand() % COL;

		++times;

	} while (GameSquare[x][y] != 0 && times <= maxTimes);

	int num = 0;

	if (whitch == 0){

		num = 4;

	}else if (whitch){

		num = 2;

	}

	GameSquare[x][y] = num;

	Size++;
	
}

int square::getMark()
{
	return Mark;
}

void square::updateMark()
{

	int temp = 0;

	for (int i = 0; i <= 3; i++) {

		for (int j = 0; j <= 3; j++) {

			if (temp < GameSquare[i][j]) {

				temp = GameSquare[i][j];
			
			}

		}

	}

	Mark = temp;
}

void square::arrMove(int action){   //一行或一列上元素的移动 
	
	switch (action)
	{
	case LEFT:
		//最上面一行不动
		for (int row = 1; row < ROW; ++row)
		{

			for (int crow = row; crow >= 1; --crow)
			{

				for (int col = 0; col < COL; ++col)
				{
						//上一个格子为空
					if (GameSquare[crow - 1][col] == 0)
					{

						GameSquare[crow - 1][col] = GameSquare[crow][col];

						GameSquare[crow][col] = 0;

					}

					else
					{
							//合并
						if (GameSquare[crow - 1][col] == GameSquare[crow][col])
						{

							GameSquare[crow - 1][col] *= 2;

							GameSquare[crow][col] = 0;

						}

					}

				}

			}

		}

		break;

	case RIGHT:

			//最下面一行不动

		for (int row = ROW - 2; row >= 0; --row)
		{

			for (int crow = row; crow < ROW - 1; ++crow)
			{

				for (int col = 0; col < COL; ++col)
				{

						//上一个格子为空

					if (GameSquare[crow + 1][col] == 0)
					{

						GameSquare[crow + 1][col] = GameSquare[crow][col];

						GameSquare[crow][col] = 0;

					}

					else
					{

							//合并

						if (GameSquare[crow + 1][col] == GameSquare[crow][col])
						{

							GameSquare[crow + 1][col] *= 2;

							GameSquare[crow][col] = 0;

						}

					}

				}

			}

		}

		break;

	case UP:

		for (int col = 1; col < COL; ++col)
		{

			for (int ccol = col; ccol >= 1; --ccol)
			{

				for (int row = 0; row < ROW; ++row)
				{

						//上一个格子为空

					if (GameSquare[row][ccol - 1] == 0)
					{

						GameSquare[row][ccol - 1] = GameSquare[row][ccol];

						GameSquare[row][ccol] = 0;

					}

					else
					{

							//合并

						if (GameSquare[row][ccol - 1] == GameSquare[row][ccol])
						{

							GameSquare[row][ccol - 1] *= 2;

							GameSquare[row][ccol] = 0;

						}

					}

				}

			}

		}

		break;

	case DOWN:

		for (int col = COL - 2; col >= 0; --col)
		{

			for (int ccol = col; ccol <= COL - 2; ++ccol)
			{

				for (int row = 0; row < ROW; ++row)
				{

						//上一个格子为空

					if (GameSquare[row][ccol + 1] == 0)
					{

						GameSquare[row][ccol + 1] = GameSquare[row][ccol];

						GameSquare[row][ccol] = 0;

					}

					else
					{

							//合并

						if (GameSquare[row][ccol + 1] == GameSquare[row][ccol])
						{

							GameSquare[row][ccol + 1] *= 2;

							GameSquare[row][ccol] = 0;

						}

					}

				}

			}

		}

		break;

	}

}

void square::updateMap() {

	system("cls");

	OutPoint.write(20, 0, "2048");
	OutPoint.write(0, 20, "Press W S A D to move square.\n");
	OutPoint.write(0, 21, "Press P to pause.");

	OutPoint.write(3, 3, "┌");
	OutPoint.write(39, 3, "┐");
	OutPoint.write(3, 19, "└");
	OutPoint.write(39, 19, "┘");

	OutPoint.setColor(point::CI_YELLOW);

	for (int x = 4; x <= 38; x++) {    //输出上下两个边

		Sleep(5);

		OutPoint.write(x, 3, "─");

		OutPoint.write(42 - x, 19, "─");

	}

	for (int y = 4; y <= 18; y++) {    //输出左右两个边

		Sleep(7);

		OutPoint.write(3, 22 - y, "│");

		OutPoint.write(39, y, "│");

	}

	OutPoint.setColor(point::C_WHITE);

	int ax = 0;

	int ay = 0;

	for (int x = 9; x <= 35; x = x + 8) {       //输出数字,x,y为输出坐标

		for (int y = 5; y <= 17; y = y + 4) {

			if (GameSquare[ax][ay]) {

				OutPoint.write(x, y, GameSquare[ax][ay]);

			}
			else {

				OutPoint.write(x, y, " ");

			}

			ay++;

		}

		ax++;

		ay = 0;

	}

	OutPoint.setColor(point::C_RED);
	OutPoint.write(29, 21, ">>>");
	OutPoint.setColor(point::C_WHITE);

}

void square::clear()
{
	Size = 0;
	Mark = 0;
	Difficulty = DIFFICULTY_INIT;

	for (int i = 0; i <= COL;i++) {
		
		for (int j = 0; j <= ROW; j++) {

			GameSquare[i][j] = 0;

		}

	}
}
