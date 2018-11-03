#include "stdafx.h"
#include "start.h"

int start::Main(){

	setConsole();

	Game2048.run();

	return 0;

	
}

void start::setConsole(){
	system("title 2048");
	system("mode con cols=45 lines=22");
}
