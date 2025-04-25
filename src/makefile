NAME=Main

all:
	g++ -static-libgcc -static-libstdc++  -Ofast -o ../bin/$(NAME).exe *.cpp -I ../include -L ../lib

debug:
	g++ -static-libgcc -static-libstdc++ -o ../bin/$(NAME)Debug.exe *.cpp -D NDEBUG -I ../include -L ../lib