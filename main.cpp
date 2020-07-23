// A hello world program in C++

#include <iostream>
#include "GOL.h"
#include "graphical.hpp"

using namespace std;

int main()
{
    //initalizing variables
    int size = 10;
    int** board = Init_game(size);
    bool not_cont = false;

    //Seting game board with display
    board = Rand_board(board, size);
    Setup();

    //main Loop, updates game baord
    while(!not_cont){
        not_cont = Draw(board,size);
        board = Forward_one_step(board,size);
    }
    cout<<"Goodbye!\n";
    
    return (1);
}
