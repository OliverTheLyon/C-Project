

/* Name:
 *      int Init_game(int length, int width)
 *
 * Description:
 *      This is the initalization function for the game board for the Game Of 
 *      Life. The game board in initalized to all dead cells to begin the game.
 *      
 * Inputs:
 *      length      INTEGER             -Number of columns in the game board
 *      width       INTEGER             -Number of rows in the game board
 *
 * Outputs:
 *      board       2D ARRAY OF INT     -Game board size (length * width) 
 *                                       initalized to 0. 
 */
int Init_game(int length, int width);



/* Name:
 *      int Forward_one_step(int board)
 *
 *Description:
 *      This function takes in a game board and applies the rules to forward 
 *      it one time step.
 *
 *Inputs:
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *
 *Outputs: 
 *      board       2D ARRAY OF INT     -Game board with all the cells 
 *                                       containing either a 1 or a 0.
 *
 */
int Forward_one_step(int board);

