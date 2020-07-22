#include <iostream>

void Print_board(int** board, int height, int width){
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            std::cout<<board[i][j];
        }
        std::cout<<'\n';
    }
}

int** Rand_board(int** board, int height, int width){
    for(int i=0; i < height; i++){
        for(int j=0; j < width; j++){
            board[i][j] = rand()%2;
        }
    }
   return(board);
}

int** Init_game(int length, int width){
    
    //safty checking the inputs
    if (!(0 < length) || !(0 < width)){
        std::cout << "The board shape is not positive.\n";
        return(NULL);
    }
    

    //initalizing the board
    int **board = (int**)malloc(length*sizeof(int*));
    for (int i = 0; i < length; i++){    
        board[i] = (int*)malloc(width*sizeof(int));
        
        for (int j = 0; j < width; j++){
            //initalize to all Zeros
            board[i][j] = 0;
        }
    }
    return(board);
}


int** Forward_one_step(int** board, int height, int width){
    
    //grab a new board
    int** new_board = Init_game(height,width);
    int new_val = 0;
    int alive = 0;

    //check update new board with old boards next state
    for(int i=0; i < height; i ++){
        for(int j=0; j < width; j++){
            new_val = board[i][j];
            
            //count alive nabours
            for (int n_i = -1; n_i < 2; n_i++){
                for(int n_j = -1; n_j < 2; n_j++){
                    //Do not read self
                    if((n_i == 0) && (n_j == 0)){
                        ;
                    } 
                    else if (board[(n_i + i + height)%(height)][(n_j + j + width)%(width)] == 1){
                        alive = alive + 1;
                    }

                }
            }           
            //Check against rules
            
            //Underpop
            if(alive < 2){
                new_val = 0;
            }
            //Overpop
            else if(3 < alive){
                new_val = 0;
            }
            //reproduction
            else if((new_val == 0)&&(alive == 3)){
                new_val = 1;
            }
            //else continue with current state
            new_board[i][j] = new_val;
            alive = 0;
        }
    }
    return(new_board);
}

