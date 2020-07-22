// A hello world program in C++

#include <iostream>
#include "GOL.h"
using namespace std;

int main()
{
    int hight = 10;
    int width = 10; 
    
    int** board = Init_game(hight,width);
    //print board
    for(int i=0; i++; i<hight){
        for (int j=0; j++; j<width){
            std::cout<<int(board[i][j]);
        }
        cout<<'\n';
    }
    
    cout<<"DONE";
    return (1);
}
