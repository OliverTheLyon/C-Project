CXX = g++

CXXFLAGS = -Wall -g

GL = -l GL -l GLEW -l glut

main.o: main.cpp GOL.cpp GOL.h
	$(CXX) $(CXXFLAGS) main.cpp GOL.cpp -o main.out

graphical: graphical.o
	$(CXX) -o graphical graphical.o $(GL)

graphical.o: graphical.cpp
	$(CXX) $(CXXFLAGS) -o graphical.o -c graphical.cpp 

clean:
	sh cleanup.sh
