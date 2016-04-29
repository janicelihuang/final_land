stage_main.o : 
	g++ -c level_main.cpp
	g++ -c keyboard.cpp
	g++ level_main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean : 
	-rm -f *.o $(EXENAME)
