#test_home_block.o : test_home_block.cpp
#	test_home_block.cpp

test_night_sky.o : 
	-rm -f *.o $(EXENAME)
	g++ -c test_night_sky.cpp
	g++ test_night_sky.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean : 
	-rm -f *.o $(EXENAME)
