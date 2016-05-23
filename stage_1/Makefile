stage_main.o : 
	g++ -c level_main.cpp
	g++ -c level_main.h
	g++ -c keyboard.cpp
	g++ -c utils.cpp
	g++ -c slime.cpp
	g++ -c dark_adept.cpp
	g++ level_main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

all: $(OBJS) clean

clean : 
	-rm -f *.o $(EXENAME)
