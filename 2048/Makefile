#2048.app : 
#	g++ -o 2048.app *.cpp

2048.app : 2048.o start.o game.o key.o menu.o square.o point.o tools.o
	g++ -o 2048.app 2048.o start.o game.o key.o menu.o square.o point.o tools.o
2048.o : 2048.cpp stdafx.h start.h
start.o : start.cpp stdafx.h start.h
game.o : game.cpp stdafx.h game.h
key.o : key.cpp stdafx.h key.h
menu.o : menu.cpp stdafx.h menu.h
square.o : square.cpp stdafx.h square.h
point.o : point.cpp stdafx.h point.h
tools.o : tools.cpp stdafx.h tools.h

clean :
	rm -r *.o 2048.app
