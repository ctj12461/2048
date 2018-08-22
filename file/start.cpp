#include "stdafx.h"
#include "start.h"

int start::Main(){

	SetConsole();

	game_2048.run();

	return 0;

	
}

void start::SetConsole(){
	system("title 2048");
	system("mode con cols=45 lines=22");
}
