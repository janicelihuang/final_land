#test_home_block.o : test_home_block.cpp
#	test_home_block.cpp

test_home_block.o : 
	-rm -f *.o $(EXENAME)
	g++ -c test_home_block.cpp
	g++ -c test_night_sky.cpp
	g++ test_home_block.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

clean : 
	-rm -f *.o $(EXENAME)
