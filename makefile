NAME=Main

all:
	g++ -static-libgcc -static-libstdc++ -Ofast -o bin/$(NAME).exe src/*.cpp -D NDEBUG -I include -L lib

debug:
	g++ -static-libgcc -static-libstdc++ -o bin/$(NAME)Debug.exe src/*.cpp -I include -L lib
