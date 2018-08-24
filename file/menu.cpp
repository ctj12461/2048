#include "stdafx.h"
#include "menu.h"

using namespace std;

menu::menu()
:menupoint()
{
}

//作用：输出程序一级菜单（功能选择）
//预览：
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

//作用:输出二级菜单（难度选择）
//预览：
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

//作用：输出游戏中的子菜单
//预览：
//             
int menu::out_sub_menu()
{
	string sub_menu[4] = { "Sub Menu","Continue","Re-start","Quit" };

	int item = 0;

	item = out_menu(sub_menu, 3, 0, 44,3);

	return item + 2;
}

//作用：为输出菜单提供的通用函数，返回选中的菜单项
//	arr[]：将菜单的各项放入数组，其中下标为1的元素为菜单标题
//  highest：调用时，数组的最后的元素的下标
//	index：菜单项当前被选中的位置
//  left：输出范围左边
//  right：输出范围右边
//  top：菜单标题纵坐标
//  (left + right) / 2 - (arr[0].size / 2)：left + (right - left) / 2 - (arr[0].size / 2) 
//											=left + 0.5right - 0.5left - (arr[0].size / 2) 
//											=0.5left + 0.5right - (arr[0].size / 2)   ......
//	for循环：不确定数组大小，使用循环遍历
//	top + i + 1：从第一个菜单项开始的纵坐标是5，而第一个菜单项的数组下标为1，所以就为top + 2 + i - 1 = 5，往下就为top + i + 1
int menu::out_menu(string arr[], int highest, int left, int right, int top) {

	int ox;    //输出位置的横坐标
	int oy = top;      //输出位置的纵坐标

	int input_index = 0;

	system("cls");

	menupoint.write(20, 0, "2048");

	ox = ((left + right) / 2) - (static_cast<int>(arr[0].size()) / 2);

	menupoint.set_color(point::C_CYAN);
	menupoint.write(ox, oy, arr[0]);     //输出菜单标题

	for (int i = left; i <= right; i++) {

		menupoint.write(i, oy + 1, "─");    //输出菜单标题与菜单项之间的分割线

	}
	
	menupoint.set_color(point::CI_GREEN);

	for (int i = 1; i <= highest; i++) {      //输出菜单项

		ox = ((left + right) / 2) - (static_cast<int>(arr[i].size()) / 2);
		oy = top + i + 1;

		menupoint.write(ox, oy, arr[i]);
	
	}
	
	menupoint.set_color(point::C_WHITE);

	do {
			
		menupoint.write(0, oy + 2, "Please press the index.\n");	//提示

		cin >> input_index;

		if (input_index < 1 || input_index > highest) {

			menupoint.set_color(point::CI_RED);
			menupoint.write(0, 21, "Please don't press any other key.");		//输入错误
			menupoint.set_color(point::C_WHITE);

		}

	
	} while (input_index < 1 || input_index > highest);

	return input_index;

}
