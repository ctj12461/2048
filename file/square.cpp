#include "stdafx.h"
#include "square.h"


using namespace std;

//��Ϸ�㷨���� 
#define COL 4
#define ROW 4

square::square()
:size(0),mark(0),Difficulty(DIFFICULTY_INIT),outpoint()
{
	Clear();
	
}

square::square(difficulty diff)
:Difficulty(diff), size(0), mark(0), outpoint()
{
	Clear();
}

void square::SetDifficulty(difficulty diff)
{
	Difficulty = diff;
}

void square::changesquare(int action){
	
	arrmove(action);

}
		
int square::isover(){
	
	int diffNum = static_cast<int>(Difficulty);

	for (int i = 0; i < ROW; ++i)

	{

		for (int j = 0; j < COL; ++j)

		{

			if (gamesquare[i][j] == diffNum)

			{

				return WIN;

			}

		}

	}



	//������

	for (int i = 0; i < ROW; ++i)

	{

		for (int j = 0; j < COL - 1; ++j)

		{

			if (!gamesquare[i][j] || (gamesquare[i][j] == gamesquare[i][j + 1]))

			{

				return RUNNING;

			}

		}

	}

	//������

	for (int j = 0; j< COL; ++j)

	{

		for (int i = 0; i < ROW - 1; ++i)

		{

			if (!gamesquare[i][j] || (gamesquare[i][j] == gamesquare[i + 1][j]))

			{

				return RUNNING;

				break;

			}

		}

	}



	//��������������״������Ϸ����

	return LOST;
	
}
		
void square::update(){
	
	int x = -1;

	int y = -1;

	int times = 0;

	int maxTimes = ROW * COL;

	//����֮���ĸ�������2������֮һ�ĸ�������4

	int whitch = rand() % 3;

	do

	{

		x = rand() % ROW;

		y = rand() % COL;

		++times;

	} while (gamesquare[x][y] != 0 && times <= maxTimes);

	int num = 0;

	if (whitch == 0){

		num = 4;

	}else if (whitch){

		num = 2;

	}

	gamesquare[x][y] = num;

	size++;
	
}

int square::get_mark()
{

	int temp = 0;

	for (int i = 0; i <= 3; i++) {

		for (int j = 0; j <= 3; j++) {

			if (temp > gamesquare[i][j]) {

				temp = gamesquare[i][j];
			
			}

		}

	}

	return temp;
}

void square::arrmove(int action){   //һ�л�һ����Ԫ�ص��ƶ� 
	

	

		switch (action)
		{
		case LEFT:

			//������һ�в���

			for (int row = 1; row < ROW; ++row)
			{

				for (int crow = row; crow >= 1; --crow)
				{

					for (int col = 0; col < COL; ++col)
					{
						//��һ������Ϊ��
						if (gamesquare[crow - 1][col] == 0)
						{

							gamesquare[crow - 1][col] = gamesquare[crow][col];

							gamesquare[crow][col] = 0;

						}

						else
						{
							//�ϲ�
							if (gamesquare[crow - 1][col] == gamesquare[crow][col])
							{

								gamesquare[crow - 1][col] *= 2;

								gamesquare[crow][col] = 0;

							}

						}

					}

				}

			}

			break;

		case RIGHT:

			//������һ�в���

			for (int row = ROW - 2; row >= 0; --row)
			{

				for (int crow = row; crow < ROW - 1; ++crow)
				{

					for (int col = 0; col < COL; ++col)
					{

						//��һ������Ϊ��

						if (gamesquare[crow + 1][col] == 0)

						{

							gamesquare[crow + 1][col] = gamesquare[crow][col];

							gamesquare[crow][col] = 0;

						}

						else
						{

							//�ϲ�

							if (gamesquare[crow + 1][col] == gamesquare[crow][col])
							{

								gamesquare[crow + 1][col] *= 2;

								gamesquare[crow][col] = 0;

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

						//��һ������Ϊ��

						if (gamesquare[row][ccol - 1] == 0)
						{

							gamesquare[row][ccol - 1] = gamesquare[row][ccol];

							gamesquare[row][ccol] = 0;

						}

						else
						{

							//�ϲ�

							if (gamesquare[row][ccol - 1] == gamesquare[row][ccol])
							{

								gamesquare[row][ccol - 1] *= 2;

								gamesquare[row][ccol] = 0;

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

						//��һ������Ϊ��

						if (gamesquare[row][ccol + 1] == 0)
						{

							gamesquare[row][ccol + 1] = gamesquare[row][ccol];

							gamesquare[row][ccol] = 0;

						}

						else
						{

							//�ϲ�

							if (gamesquare[row][ccol + 1] == gamesquare[row][ccol])
							{

								gamesquare[row][ccol + 1] *= 2;

								gamesquare[row][ccol] = 0;

							}

						}

					}

				}

			}

			break;

		}

}

void square::updatemap() {

	system("cls");

	outpoint.write(20, 0, "2048");
	outpoint.write(0, 20, "Press W S A D to move square.\n");
	outpoint.write(0, 21, "Press P to pause.");

	outpoint.write(3, 3, "��");
	outpoint.write(39, 3, "��");
	outpoint.write(3, 19, "��");
	outpoint.write(39, 19, "��");

	for (int x = 4; x <= 38; x++) {    //�������������

		Sleep(10);

		outpoint.write(x, 3, "��");

		outpoint.write(42 - x, 19, "��");

	}

	for (int y = 4; y <= 18; y++) {    //�������������

		Sleep(15);

		outpoint.write(3, 22 - y, "��");

		outpoint.write(39, y, "��");

	}

	int ax = 0;

	int ay = 0;

	for (int x = 9; x <= 35; x = x + 8) {       //�������,x,yΪ�������

		for (int y = 5; y <= 17; y = y + 4) {

			if (gamesquare[ax][ay]) {

				outpoint.write(x, y, gamesquare[ax][ay]);

			}
			else {

				outpoint.write(x, y, " ");

			}

			ay++;

		}

		ax++;

		ay = 0;

	}

	outpoint.write(29, 21, ">>>");
}

void square::Clear()
{
	size = 0;
	mark = 0;
	Difficulty = DIFFICULTY_INIT;

	for (int i = 0; i <= COL;i++) {
		
		for (int j = 0; j <= ROW; j++) {

			gamesquare[i][j] = 0;

		}

	}
}
