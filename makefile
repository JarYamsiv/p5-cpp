all:main.cpp sdlm
	g++ -g main.cpp obj/SDLM.o -o bin/app -lSDL2 -lpthread

sdlm:src/SDLM.cpp headers/SDLM.h
	g++ -c src/SDLM.cpp -o obj/SDLM.o