# PONDER 09 SIZE ESTIMATION

## Three SIs 

### SI 1: Macros
In the source-code for Tic-Tac-Toe, there are several functions assuming that the pieces 
in the Tic-Tac-Toe game are either 'X', 'O', or a '.' (displayed as a space to the user). 
Please modify this code so there are #define macros rather than the hard-coded 'X', 'O', and '.'.

Additionally, create a #define for the size of the board rather than using the literal integer 3. 
Everything should work if this is changed to a 2 for a 2x2 board or a 5 for a 5x5 board. 
Recall that the code needs to be tested before it counts as completed.

### SI 2: Winning
Modify the code from SI 1 to indicate who won the game. 
In this file, you will find a function called didWin() that is currently stubbed out. 
Write the necessary code to determine if X did in fact win this game. 
This occurs if either the X player or the O player has a 3-in-a-row or a diagonal. 
Note that the size of the board does not have to be 3x3. 
(See the change from Experiment 1). 
If the board is 4x4, then the user must get 4-in-a-row or one of the diagonals.

### SI 3: Three Dimensions
Start with the code from SI 2. 
Modify the game so it can read, write, display, and determine whether a given player has won 
for the 3D version of the game. ]
