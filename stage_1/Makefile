stage_1.o : 
	g++ -c stage_1.cpp
	g++ -c keyboard.cpp
	g++ stage_1.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean : 
	-rm -f *.o $(EXENAME)
