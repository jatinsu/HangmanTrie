CXX = g++
CXXFLAGS = -Wall -g

# mytest: hangman.o mytest.cpp
# 	$(CXX) $(CXXFLAGS) hangman.o mytest.cpp -o mytest
program: hangman.o program.cpp
	$(CXX) $(CXXFLAGS) hangman.o program.cpp -o program
hangman.o: hangman.cpp
	$(CXX) $(CXXFLAGS) -c hangman.cpp
val:
	valgrind ./program