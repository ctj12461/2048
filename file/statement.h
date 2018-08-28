/////////////////////////////////////////////////////////////
//            2048
//版本 Version Release 4.2.0.0
//系统 OS Windows x86 x64
//作者 Writer Ctj
//日期 Date 2018-08-28 星期五 Friday
//自由软件（开放源码），拷贝请标明作者 Free（Open Sources）


#ifndef STATEMENT_H
#define STATEMENT_H

//版本
#define VERSION "4.2.0.0"
#define DATE_ "#2018-08-28#"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define KEY_UP 0
#define KEY_DOWN 1
#define KEY_LEFT 2
#define KEY_RIGHT 3
//一级菜单项
#define ITEM_NEW_GAME 1
#define ITEM_HIGHEST_SCORE 2
#define ITEM_ABOUT 3
#define ITEM_QUIT_FIRST 4

//二级菜单项
#define ITEM_EASY 1
#define ITEM_MIDDLE 2
#define ITEM_DIFFICULT 3
#define ITEM_QUIT_SECOND 4

//游戏结果
#define RUNNING 0
#define WIN 1
#define LOST 2

//子菜单返回值
#define CONTINUE 3
#define RE_START 4
#define QUIT 5

#endif
