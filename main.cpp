#include <iostream>
#include <iomanip>
using namespace std;

const int gridSize = 4;

int grid[gridSize][gridSize];

void initializeGrid(int grid[gridSize][gridSize])
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void displayGrid(int grid[gridSize][gridSize])
{
    cout << "-----------------------------" << endl;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cout << setw(4) << grid[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "-----------------------------" << endl;
}
void columnCheck(int grid[gridSize][gridSize], int row, int column)
{
    if (row - 1 >= 0) // doesnt check if the number is in the first row
    {
        if (row - 1 >= 0 && grid[row - 1][column] == 0) // check if the number above is 0, if it is then push the current number up
        {
            grid[row - 1][column] = grid[row][column];
            grid[row][column] = 0;
            displayGrid(grid);
            return;
        }

        if (grid[row][column] == grid[row - 1][column]) // check if the number above is equal to the current number, if it is then add them together
        {
            grid[row - 1][column] = grid[row][column] + grid[row - 1][column]; // check if the number above is equal to the current number
            grid[row][column] = 0;                                             // sets the lowe number to 0, technically pushing the number up
            displayGrid(grid);
        }
    }
}

int main()
{
    initializeGrid(grid);
    displayGrid(grid);

    while (true)
    {
        int column;
        int number = 2;
        cout << "Enter the column number: ";
        cin >> column;
        column = column - 1;

        for (int i = 0; i <= gridSize - 1; i++)
        {

            displayGrid(grid);
            if (grid[i][column] == 0 || grid[i][column] == number)
            {
                grid[i][column] = grid[i][column] + number;
                columnCheck(grid, i, column);

                break;
            }
            columnCheck(grid, i, column);
            displayGrid(grid);
        }

        displayGrid(grid);
    }
    return 0;
}