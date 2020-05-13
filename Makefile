
CXX = g++

CXXFLAGS = -Wall -g

GI = -I ./eigen
GL = -l GL -l GLEW -l glut 

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -o main.o main.cpp


graphical: graphical.o
	$(CXX) -o graphical graphical.o $(GL)

graphical.o: graphical.cpp
	$(CXX) $(CXXFLAGS) -o graphical.o -c graphical.cpp $(GI)

clean:
	sh cleanup.sh
