/***********************************************************************
* Program:
*    Lesson 08, Tic-Tac-Toe
* Summary:
*    This program reads, displays, and writes a Tic-Tac-Toe board
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#define X "X"
#define O "O"
#define S "."
#define SIZE_OF_BOARD 3

bool read(char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], const char* fileName);
bool write(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], const char* fileName);
void display(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD]);
bool didWin(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], char turn);

/**********************************************************************
 * Keeps the data and calles the read/display/write functions
 ***********************************************************************/
int main()
{
    char board[SIZE_OF_BOARD][SIZE_OF_BOARD][SIZE_OF_BOARD];

    // read the board
    char fileName[256];
    cout << "Enter source filename: ";
    cin >> fileName;
    if (!read(board, fileName))
    {
        cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
        return 1;
    }

    // display the board
    display(board);

    // write the board to a file
    cout << "Enter destination filename: ";
    cin >> fileName;

    if (!write(board, fileName))
    {
        cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
        return 1;
    }

    return 0;
}

/**************************************************************
 * READ
 * Read the board from the specified filename
 *************************************************************/
bool read(char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], const char* fileName)
{
    assert(*fileName);

    // open the file
    ifstream fin(fileName);
    if (fin.fail())
        return false;

    // read 9 symbols, hopefully they are . X O
    for (int d = 0; d < SIZE_OF_BOARD; d++)
        for (int r = 0; r < SIZE_OF_BOARD; r++)
            for (int c = 0; c < SIZE_OF_BOARD; c++)
            {
                fin >> board[d][r][c];
                assert(!fin.fail());
                assert(board[d][r][c] == *X ||
                    board[d][r][c] == *O ||
                    board[d][r][c] == *S);
            }

    // close the file
    fin.close();
    return true;
}

/**********************************************************
 * WRITE
 * Write to fileName the board data
 *********************************************************/
bool write(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], const char* fileName)
{
    assert(fileName[0] != '\0');

    // open the file
    ofstream fout(fileName);
    if (fout.fail())
        return false;

    // write my 9 symbols
    for (int d = 0; d < SIZE_OF_BOARD; d++)
        for (int r = 0; r < SIZE_OF_BOARD; r++)
            for (int c = 0; c < SIZE_OF_BOARD; c++)
                fout << board[d][r][c] << (c == SIZE_OF_BOARD - 1 ? '\n' : ' ');

    // close it!
    fout.close();
    cout << "File written\n";
    return true;
}

/*******************************************************
 * DISPLAY
 * Display the contents the the screen
 *****************************************************/
void display(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD])
{
    for (int d = 0; d < SIZE_OF_BOARD; d++)
    {
        cout << "\nLevel " << d + 1 << endl;
        // loop through each row
        for (int r = 0; r < SIZE_OF_BOARD; r++)
        {
            // only the first row is not preceeded with the --+-- magic
            if (r != 0)
                for (int i = 0; i < SIZE_OF_BOARD; i++)
                    if (i != SIZE_OF_BOARD - 1)
                        cout << "---+";
                    else
                        cout << "---\n";

            // now, on each row, do the column stuff
            for (int c = 0; c < SIZE_OF_BOARD; c++)
            {
                // display a space for the dot
                if (board[d][r][c] == *S)
                    cout << "   ";
                else
                    cout << " " << board[d][r][c] << " ";

                // end with a | or a newline
                cout << (c == SIZE_OF_BOARD - 1 ? '\n' : '|');
            }
        }
    }

    // display who won
    if (didWin(board, *X))
        cout << "X won!\n";
    if (didWin(board, *O))
        cout << "O won!\n";

    return;
}

    
 /********************************************
 * DID WIN
 * Did a given player (determined by the "turn"
 * variable) win the game?
 *******************************************/
    bool didWin(const char board[][SIZE_OF_BOARD][SIZE_OF_BOARD], char turn)
    {
        for (int d = 0; d < SIZE_OF_BOARD; d++)
            for (int r = 0; r < SIZE_OF_BOARD; r++)
                for (int c = 0; c < SIZE_OF_BOARD; c++)
                {

                    if (d == 0 &&
                        r == 0 ||
                        c == 0 ||
                        r == SIZE_OF_BOARD - 1 ||
                        c == SIZE_OF_BOARD - 1) // depth diagonal
                    {
                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check ROWS
                        {
                            if (board[dep][dep][c] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }

                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check COLUMNS
                        {
                            if (board[dep][r][dep] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }
                       
                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check TOP LEFT CORNER
                        {
                            if (board[dep][dep][dep] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }

                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check TOP RIGHT CORNER
                        {
                            int x = SIZE_OF_BOARD - dep - 1; 
                            if (board[dep][dep][x] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }

                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check BOTTOM LEFt CORNER
                        {
                            int y = SIZE_OF_BOARD - dep - 1;
                            if (board[dep][y][dep] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }

                        for (int dep = 0; dep < SIZE_OF_BOARD; dep++) // check BOTTOM RIGHT CORNER
                        {
                            int coordinate = SIZE_OF_BOARD - dep - 1;
                            if (board[dep][coordinate][coordinate] != turn)
                                break;
                            if (dep == SIZE_OF_BOARD - 1)
                                return true;
                        }
                    }


                    for (int dep = 0; dep < SIZE_OF_BOARD; dep++) 
                        // check for depth wins
                    {
                        if (board[dep][r][c] != turn)
                            break;
                        if (dep == SIZE_OF_BOARD - 1)
                            return true;
                    }

                    for (int col = 0; col < SIZE_OF_BOARD; col++) // column
                    {
                        if (board[d][r][col] != turn)
                            break;
                        if (col == SIZE_OF_BOARD - 1)
                            return true;
                    }

                    for (int row = 0; row < SIZE_OF_BOARD; row++) // row
                    {
                        if (board[d][row][c] != turn)
                            break;
                        if (row == SIZE_OF_BOARD - 1)
                            return true;
                    }

                    if (r == c) // diagonal
                        for (int i = 0; i < SIZE_OF_BOARD; i++) 
                        {
                            if (board[d][i][i] != turn)
                                break;
                            if (i == SIZE_OF_BOARD - 1)
                                return true;
                        }

                    if (r + c == SIZE_OF_BOARD - 1) // reverse diagonal
                        for (int i = 0; i < SIZE_OF_BOARD; i++) 
                        {
                            if (board[d][i][(SIZE_OF_BOARD - 1) - i] != turn)
                                break;
                            if (i == SIZE_OF_BOARD - 1)
                                return true;
                        }
                }
        return false;
    }
