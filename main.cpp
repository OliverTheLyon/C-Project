// A hello world program in C++

#include <iostream>
#include "GOL.h"
using namespace std;

int main()
{
    int height = 5;
    int width = 5; 
    
    int** board = Init_game(height,width);
    board = Rand_board(board, height, width);
    Print_board(board,height,width);
    cout<<"--------------\n";
    board = Forward_one_step(board,height,width);
    Print_board(board,height,width);
    cout<<"DONE";
    return (1);
}
