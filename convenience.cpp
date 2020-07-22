
#ifndef CON
#define CON
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#endif

using namespace std;

bool ReadFile(const char * file, string& out){
	
	ifstream f(file);

	bool ret = false;

	if(f.is_open()){
		string line;
		while(getline(f, line)){
			out.append(line);
			out.append("\n");

		}

		f.close();

		ret = true;
	}
	else{
		fprintf(stderr, "Provided file, %s, was not open\n", file);
		ret = false;
	}

	return ret;
}
