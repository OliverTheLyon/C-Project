
CXX = g++

CXXFLAGS = -Wall -g

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o main.o main.cpp

