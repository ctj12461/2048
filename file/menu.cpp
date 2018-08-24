#include "stdafx.h"
#include "menu.h"

using namespace std;

menu::menu()
:menupoint()
{
}

//���ã��������һ���˵�������ѡ��
//Ԥ����
//	             Main Menu
//------------------------------------------
//               New Game
//            Highest Score
//				  About
//				  Quit
int menu::out_first_menu(){

	string first_menu[5] = {"Main Menu","New Game","Highest Score","About","Quit"};

	int item = 0;

	item = out_menu(first_menu,4, 0, 44, 3);

	return item;
}

//����:��������˵����Ѷ�ѡ��
//Ԥ����
//			  Difficulty Choice
//------------------------------------------
//				 Easy(2048)
//				Middle(8192)
//			  Difficult(65536)
//				  Quit
int menu::out_second_menu(){

	string second_menu[5] = { "Difficulty Choice","Easy(2048)","Middle(8192)","Difficult(65536)","Quit" };

	int item = 0;

	item = out_menu(second_menu, 4, 0, 44, 3);

	return item;

}

//���ã������Ϸ�е��Ӳ˵�
//Ԥ����
//             
int menu::out_sub_menu()
{
	string sub_menu[4] = { "Sub Menu","Continue","Re-start","Quit" };

	int item = 0;

	item = out_menu(sub_menu, 3, 0, 44,3);

	return item + 2;
}

//���ã�Ϊ����˵��ṩ��ͨ�ú���������ѡ�еĲ˵���
//	arr[]�����˵��ĸ���������飬�����±�Ϊ1��Ԫ��Ϊ�˵�����
//  highest������ʱ�����������Ԫ�ص��±�
//	index���˵��ǰ��ѡ�е�λ��
//  left�������Χ���
//  right�������Χ�ұ�
//  top���˵�����������
//  (left + right) / 2 - (arr[0].size / 2)��left + (right - left) / 2 - (arr[0].size / 2) 
//											=left + 0.5right - 0.5left - (arr[0].size / 2) 
//											=0.5left + 0.5right - (arr[0].size / 2)   ......
//	forѭ������ȷ�������С��ʹ��ѭ������
//	top + i + 1���ӵ�һ���˵��ʼ����������5������һ���˵���������±�Ϊ1�����Ծ�Ϊtop + 2 + i - 1 = 5�����¾�Ϊtop + i + 1
int menu::out_menu(string arr[], int highest, int left, int right, int top) {

	int ox;    //���λ�õĺ�����
	int oy = top;      //���λ�õ�������

	int input_index = 0;

	system("cls");

	menupoint.write(20, 0, "2048");

	ox = ((left + right) / 2) - (static_cast<int>(arr[0].size()) / 2);

	menupoint.set_color(point::C_CYAN);
	menupoint.write(ox, oy, arr[0]);     //����˵�����

	for (int i = left; i <= right; i++) {

		menupoint.write(i, oy + 1, "��");    //����˵�������˵���֮��ķָ���

	}
	
	menupoint.set_color(point::CI_GREEN);

	for (int i = 1; i <= highest; i++) {      //����˵���

		ox = ((left + right) / 2) - (static_cast<int>(arr[i].size()) / 2);
		oy = top + i + 1;

		menupoint.write(ox, oy, arr[i]);
	
	}
	
	menupoint.set_color(point::C_WHITE);

	do {
			
		menupoint.write(0, oy + 2, "Please press the index.\n");	//��ʾ

		cin >> input_index;

		if (input_index < 1 || input_index > highest) {

			menupoint.set_color(point::CI_RED);
			menupoint.write(0, 21, "Please don't press any other key.");		//�������
			menupoint.set_color(point::C_WHITE);

		}

	
	} while (input_index < 1 || input_index > highest);

	return input_index;

}
