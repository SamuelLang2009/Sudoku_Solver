#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

#define SIZE 9

bool checkCoordinate(int x, int y, int value, int SUDOKU[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        if (SUDOKU[y][i] == value)
        {
            return false;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        if (SUDOKU[i][x] == value)
        {
            return false;
        }
    }

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(SUDOKU[i][j] == value && i/3 == y/3 && j/3 == x/3)
            {
                return false;
            }
        }
    }

    return true;
}

void printSudoku(int SUDOKU[][SIZE])
{
    system("cls");
    for(int i = 0; i < SIZE; i++)
    {
        cout << "| ";
        for(int j = 0; j < SIZE; j++)
        {
            cout << SUDOKU[i][j] << " | ";
        }
        cout << "\n____________________________________\n";
    }
}

int main()
{
    int SUDOKU[SIZE][SIZE] = {
        {2,7,0,3,0,0,0,0,5},
        {0,1,0,0,0,6,2,0,0},
        {6,0,0,5,0,0,0,0,0},
        {0,0,7,6,0,0,0,5,0},
        {5,0,0,0,0,0,0,0,6},
        {0,3,0,0,0,7,1,0,0},
        {0,0,0,0,0,3,0,0,4},
        {0,0,3,7,0,0,0,9,0},
        {9,0,0,0,0,2,0,6,7}
    };

    vector<int> X_Coordinates;
    vector<int> Y_Coordinates;
    vector<int> tracker;

    int counter = 0;

    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            if(SUDOKU[row][col] == 0)
            {
                tracker.push_back(0);
                Y_Coordinates.push_back(row);
                X_Coordinates.push_back(col);
            }
        }
    }

    while(counter < X_Coordinates.size())
    {
        tracker[counter]++;

        if(tracker[counter] > SIZE)
        {
            tracker[counter] = 0;
            SUDOKU[Y_Coordinates[counter]][X_Coordinates[counter]] = tracker[counter];
            counter -= 1;
        }

        bool check = checkCoordinate(X_Coordinates[counter], Y_Coordinates[counter], tracker[counter], SUDOKU);

        if(check)
        {
            SUDOKU[Y_Coordinates[counter]][X_Coordinates[counter]] = tracker[counter];
            //printSudoku(SUDOKU);
            counter += 1;
        }
    }

    printSudoku(SUDOKU);
}