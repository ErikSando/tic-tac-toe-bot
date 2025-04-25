NAME=Main

all:
	g++ -static-libgcc -static-libstdc++  -Ofast -o ../bin/$(NAME).exe *.cpp -I ../include -L ../lib

debug:
	g++ -static-libgcc -static-libstdc++ -o ../bin/$(NAME)Debug.exe -D NDEBUG *.cpp -I ../include -L ../lib