/*
------------------------------------------------------
Project Name : Sudoku Solver
Internship    : CodeAlpha C++ Programming Internship
Developed By  : Namra Saleem Ahmed

Description:
This program solves a 9x9 Sudoku puzzle using the
Backtracking Algorithm.
------------------------------------------------------
*/

#include <iostream>

using namespace std;

//===========================
// Function Prototypes
//===========================

void printBoard(int board[9][9]);

bool isSafe(int board[9][9], int row, int col, int number);

bool solveSudoku(int board[9][9]);

//===========================
// Main Function
//===========================

int main()
{
    int board[9][9] =
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},

        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},

        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout<<"=============================================\n";
    cout<<"      CODEALPHA SUDOKU SOLVER\n";
    cout<<"=============================================\n\n";

    cout<<"Original Sudoku\n\n";

    printBoard(board);

    cout<<"\n\nSolving Puzzle...\n\n";

    if(solveSudoku(board))
    {
        cout<<"Sudoku Solved Successfully!\n\n";

        printBoard(board);
    }

    else
    {
        cout<<"No Solution Exists.\n";
    }

    return 0;
}
//================================================
// Display Sudoku Board
//================================================

void printBoard(int board[9][9])
{
    cout << "-------------------------\n";

    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            if(col == 0)
                cout << "| ";

            if(board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";

            if((col + 1) % 3 == 0)
                cout << "| ";
        }

        cout << endl;

        if((row + 1) % 3 == 0)
            cout << "-------------------------\n";
    }
}


//================================================
// Check if Number Can Be Placed Safely
//================================================

bool isSafe(int board[9][9], int row, int col, int number)
{

    // Check Row
    for(int x = 0; x < 9; x++)
    {
        if(board[row][x] == number)
        {
            return false;
        }
    }


    // Check Column
    for(int x = 0; x < 9; x++)
    {
        if(board[x][col] == number)
        {
            return false;
        }
    }


    // Check 3x3 Box
    int startRow = row - row % 3;
    int startCol = col - col % 3;


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i + startRow][j + startCol] == number)
            {
                return false;
            }
        }
    }


    return true;
}
//================================================
// Sudoku Solver Using Backtracking Algorithm
//================================================

bool solveSudoku(int board[9][9])
{

    int row = -1;
    int col = -1;

    bool emptyCell = false;


    // Find Empty Cell
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {

            if(board[i][j] == 0)
            {
                row = i;
                col = j;
                emptyCell = true;
                break;
            }

        }

        if(emptyCell)
            break;
    }


    // If No Empty Cell Found
    // Sudoku Is Already Solved
    if(!emptyCell)
    {
        return true;
    }



    // Try Numbers From 1 To 9
    for(int number = 1; number <= 9; number++)
    {

        if(isSafe(board, row, col, number))
        {

            // Place Number
            board[row][col] = number;


            // Continue Solving
            if(solveSudoku(board))
            {
                return true;
            }


            // Backtrack
            // Remove Number If It Does Not Work
            board[row][col] = 0;

        }

    }


    // No Number Worked
    return false;
}
