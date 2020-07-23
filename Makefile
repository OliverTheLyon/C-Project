CXX = g++

CXXFLAGS = -Wall -g

GL = -l GL -l GLEW -l glfw 

main.out: main.o GOL.o graphical.o convenience.o
	$(CXX) main.o GOL.o graphical.o convenience.o -o main.out $(GL)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o 

GOL.o: GOL.cpp
	$(CXX) $(CXXFLAGS) -c GOL.cpp -o GOL.o


gtest: graphical
	./graphical

graphical: graphical.o convenience.o
	$(CXX) -o graphical graphical.o convenience.o $(GL)

graphical.o: graphical.cpp
	$(CXX) $(CXXFLAGS) -o graphical.o -c graphical.cpp 

convenience.o: convenience.cpp
	$(CXX) $(CXXFLAGS) -o convenience.o -c convenience.cpp

clean:
	sh cleanup.sh
