CXX = g++

CXXFLAGS = -Wall -g

GI = -I ./eigen -I ./eigen/unsupported
GL = -l GL -l GLEW -l glut 

main.o: main.cpp GOL.cpp GOL.h
	$(CXX) $(CXXFLAGS) main.cpp GOL.cpp -o main.out


gtest: graphical
	./graphical

graphical: graphical.o
	$(CXX) -o graphical graphical.o $(GL)

graphical.o: graphical.cpp
	$(CXX) $(CXXFLAGS) -o graphical.o -c graphical.cpp $(GI)

clean:
	sh cleanup.sh
