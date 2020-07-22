#include <iostream>


int** Init_game(int length, int width){
    
    //safty checking the inputs
    if (!(0 < length) || !(0 < width)){
        std::cout << "The board shape is not positive.\n";
        return(NULL);
    }
    

    //initalizing the board
    int** board  = 0;
    board = new int*[length];
    
    for (int i = 0; i < length; i++){    
        board[i] = new int[width];
        
        for (int j = 0; j < width; j++){
            //initalize to all Zeros
            board[i][j] = 0;
        }
    }
    return(board);
}


int** Forward_one_step(int** board, int hight, int width){
    
    //grab a new board

    //check update new board with old boards next state


    return(NULL);

}

