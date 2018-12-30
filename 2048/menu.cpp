#include "stdafx.h"
#include "menu.h"

using namespace std;

menu::menu()
:MenuPoint()
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
int menu::outputMainMenu(){

	string MainMenu[5] = {"Main Menu","New Game","Highest Score","About","Quit"};

	int item = 0;

	item = outMenu(MainMenu,4, 0, 44, 3);

	return item;
}

//作用:输出二级菜单（难度选择）
//预览：
//		   Difficulty Choice Menu
//------------------------------------------
//				 Easy(2048)
//				Middle(8192)
//			  Difficult(65536)
//				Inifnite(∞)
//				  Quit
int menu::outputDifficultyChoiceMenu(){

	string DifficultChoiceMenu[6] = { "Difficulty Choice Menu","Easy(2048)","Middle(8192)","Difficult(65536)","Inifnite(∞)","Quit" };

	int item = 0;

	item = outMenu(DifficultChoiceMenu, 5, 0, 44, 3);

	return item;

}

//作用：输出游戏中的子菜单
//预览：
//             
int menu::outputSubMenu()
{
	string SubMenu[4] = { "Sub Menu","Continue","Re-start","Quit" };

	int item = 0;

	item = outMenu(SubMenu, 3, 0, 44,3);

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
int menu::outMenu(string arr[], int highest, int left, int right, int top) {

	int ox;    //输出位置的横坐标
	int oy = top;      //输出位置的纵坐标

	int input_index = 0;

	tools::clear();

	MenuPoint.write(20, 0, "2048");

	ox = ((left + right) / 2) - (static_cast<int>(arr[0].size()) / 2);

	MenuPoint.setColor(point::C_CYAN);
	MenuPoint.write(ox, oy, arr[0]);     //输出菜单标题

	for (int i = left; i <= right; i++) {

		MenuPoint.write(i, oy + 1, "─");    //输出菜单标题与菜单项之间的分割线

	}
	
	MenuPoint.setColor(point::CI_GREEN);

	for (int i = 1; i <= highest; i++) {      //输出菜单项

		ox = ((left + right) / 2) - (static_cast<int>(arr[i].size()) / 2);
		oy = top + i + 1;

		MenuPoint.write(ox, oy, arr[i]);
	
	}
	
	MenuPoint.setColor(point::C_WHITE);

	do {
			
		MenuPoint.write(0, oy + 2, "Please press the index.\n");	//提示

		cin >> input_index;

		if (input_index < 1 || input_index > highest) {

			MenuPoint.setColor(point::CI_RED);
			MenuPoint.write(0, 21, "Please don't press any other key.");		//输入错误
			MenuPoint.setColor(point::C_WHITE);

		}

	
	} while (input_index < 1 || input_index > highest);

	return input_index;

}
