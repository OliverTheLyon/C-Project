CXX = g++

CXXFLAGS = -Wall -g

GL = -l GL -l GLEW -l glfw 

main.o: main.cpp GOL.cpp graphical.o convenience.o
	$(CXX) $(CXXFLAGS) main.cpp GOL.cpp graphical.o convenience.o -o main.out


gtest: graphical
	./graphical

graphical: graphical.o convenience.o
	$(CXX) -o graphical graphical.o convenience.o $(GL)

graphical.o: graphical.cpp
	$(CXX) $(CXXFLAGS) -o graphical.o -c graphical.cpp $(GI)

convenience.o: convenience.cpp
	$(CXX) $(CXXFLAGS) -o convenience.o -c convenience.cpp

clean:
	sh cleanup.sh
