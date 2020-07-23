
/* Name: 
 *      void Print_board(int** board, int height, int width)
 *
 * Description:
 *      This function is desigend to print the current board to STD output.
 *
 * Inputs:
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *      size        INTEGER              -Hight and width of the matrix
 */
void Print_board(int** board, int size);

/*
 * Name:
 *      Rand_board(int** board, int height, int width)
 *
 * Description:
 *      THis finction is desgined to take in a board and randomly assign 1 or 0
 *      to each cell in the 2D array.
 *
 * Inputs:
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *      size        INTEGER              -Hight and width of the matrix
 *
 * Outputs:
 *      board       2D ARRAY OF INT     -Game board with either 1 or 0
 *                                       in each cell randomly assigned.     
 */
int** Rand_board(int** board, int size);

/* Name:
 *      int Init_game(int length, int width)
 *
 * Description:
 *      This is the initalization function for the game board for the Game Of 
 *      Life. The game board in initalized to all dead cells to begin the game.
 *      
 * Inputs:
 *      size        INTEGER              -Hight and width of the matrix
 *
 * Outputs:
 *      board       2D ARRAY OF INT     -Game board size (length * width) 
 *                                       initalized to 0. 
 */
int** Init_game(int size);



/* Name:
 *      int Forward_one_step(int board)
 *
 * Description:
 *      This function takes in a game board and applies the rules to forward 
 *      it one time step.
 *
 * Inputs:
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *      size        INTEGER              -Hight and width of the matrix
 *
 * Outputs: 
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *
 */
int** Forward_one_step(int** board, int size);

