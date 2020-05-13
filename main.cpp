// A hello world program in C++

#include <iostream>
#include "GOL.h"
using namespace std;

int main()
{
    int hight = 10;
    int width = 10; 
    
    int** board = Init_game(hight,width);
    
    int** new_board = Forward_one_step(board, hight, width);  
    
    return (1);
}
