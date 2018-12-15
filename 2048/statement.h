/////////////////////////////////////////////////////////////
//            2048
//Copyright (C) 2018 Justin Chen
//This software is free and open source.
//See more in README.md and LICENSE.

//#define FLAG

#ifdef FLAG
#define Linux
#else
#define Windows
#endif

#ifndef STATEMENT_H
#define STATEMENT_H

//版本
#define VERSION "6.0.0.2"

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
#define ITEM_INIFNITE 4
#define ITEM_QUIT_SECOND 5

//游戏结果
#define RUNNING 0
#define WIN 1
#define LOST 2

//子菜单返回值
#define CONTINUE 3
#define RE_START 4
#define QUIT 5

#endif