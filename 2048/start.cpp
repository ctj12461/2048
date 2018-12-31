#include "stdafx.h"
#include "start.h"

int start::Main(){

	tools::clear();

	setConsole();

	Game2048.run();

	return 0;

	
}

void start::setConsole(){
	tools::resize(45, 22);
}
