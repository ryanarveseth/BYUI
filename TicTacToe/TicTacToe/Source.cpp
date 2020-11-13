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

bool read(char board[][SIZE_OF_BOARD], const char* fileName);
bool write(const char board[][SIZE_OF_BOARD], const char* fileName);
void display(const char board[][SIZE_OF_BOARD]);
bool didWin(const char board[][SIZE_OF_BOARD], char turn);

/**********************************************************************
 * Keeps the data and calles the read/display/write functions
 ***********************************************************************/
int main()
{
    char board[SIZE_OF_BOARD][SIZE_OF_BOARD];

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
bool read(char board[][SIZE_OF_BOARD], const char* fileName)
{
    assert(*fileName);

    // open the file
    ifstream fin(fileName);
    if (fin.fail())
        return false;

    // read 9 symbols, hopefully they are . X O
    for (int r = 0; r < SIZE_OF_BOARD; r++)
        for (int c = 0; c < SIZE_OF_BOARD; c++)
        {
            fin >> board[r][c];
            assert(!fin.fail());
            assert(board[r][c] == *X ||
                board[r][c] == *O ||
                board[r][c] == *S);
        }

    // close the file
    fin.close();
    return true;
}

/**********************************************************
 * WRITE
 * Write to fileName the board data
 *********************************************************/
bool write(const char board[][SIZE_OF_BOARD], const char* fileName)
{
    assert(fileName[0] != '\0');

    // open the file
    ofstream fout(fileName);
    if (fout.fail())
        return false;

    // write my 9 symbols
    for (int r = 0; r < SIZE_OF_BOARD; r++)
        for (int c = 0; c < SIZE_OF_BOARD; c++)
            fout << board[r][c] << (c == 2 ? '\n' : ' ');

    // close it!
    fout.close();
    cout << "File written\n";
    return true;
}

/*******************************************************
 * DISPLAY
 * Display the contents the the screen
 *****************************************************/
void display(const char board[][SIZE_OF_BOARD])
{
    // loop through each row
    for (int r = 0; r < SIZE_OF_BOARD; r++)
    {
        // only the first row is not preceeded with the --+-- magic
        if (r != 0)
            cout << "---+---+---\n";

        // now, on each row, do the column stuff
        for (int c = 0; c < SIZE_OF_BOARD; c++)
        {
            // display a space for the dot
            if (board[r][c] == *S)
                cout << "   ";
            else
                cout << " " << board[r][c] << " ";

            // end with a | or a newline
            cout << (c == SIZE_OF_BOARD - 1 ? '\n' : '|');
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
    bool didWin(const char board[][SIZE_OF_BOARD], char turn)
    {
        return false;
    }




