#include <iostream>
#include <iomanip>
using namespace std;

const int gridSize = 5;

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
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cout << setw(4) << grid[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

void checkAboveValue(int grid[gridSize][gridSize], int row, int column)
{
    if (row - 1 >= 0 && grid[row - 1][column] == 0)
    {
        grid[row - 1][column] = grid[row][column];
        grid[row][column] = 0;
    }
    if (grid[row][column] == grid[row - 1][column])
    {
        grid[row - 1][column] = grid[row][column] + grid[row - 1][column];
        grid[row][column] = 0;
    }
}
void checkBelowValue(int grid[gridSize][gridSize], int row, int column)
{
    if (grid[row][column] == grid[row - 1][column]) // check if the number above is equal to the current number, if it is then add them together
    {
        grid[row - 1][column] = grid[row][column] + grid[row - 1][column]; // check if the number above is equal to the current number
        grid[row][column] = 0;                                             // sets the lowe number to 0, technically pushing the number up
    }
}

void columnCheck(int grid[gridSize][gridSize], int row, int column)
{

    if (row - 1 >= 0) // doesnt check if the number is in the first row
    {
        checkAboveValue(grid, row, column);
        checkBelowValue(grid, row, column);
    }
}

void checkLeftValue(int grid[gridSize][gridSize], int row, int column)
{
    if (grid[row][column] == grid[row][column - 1]) // checks the number on its left
    {
        grid[row][column - 1] = grid[row][column] + grid[row][column - 1];
        grid[row][column] = 0;
    }
}
void checkRightValue(int grid[gridSize][gridSize], int row, int column)
{
    if (grid[row][column] == grid[row][column + 1]) // checks the number on its right
    {
        grid[row][column + 1] = grid[row][column] + grid[row][column + 1];
        grid[row][column] = 0;
    }
}

void rowCheck(int grid[gridSize][gridSize], int row, int column)
{
    checkRightValue(grid, row, column);
    checkLeftValue(grid, row, column);
}

void checkAll(int grid[gridSize][gridSize])
{
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (i - 1 >= 0)
            {
                checkAboveValue(grid, i, j);
            }

            if (i + 1 < gridSize)
            {
                checkBelowValue(grid, i, j);
            }

            if (j - 1 >= 0)
            {
                checkLeftValue(grid, i, j);
            }

            if (j + 1 < gridSize)
            {
                checkRightValue(grid, i, j);
            }
        }
    }
}

int main()
{
    initializeGrid(grid);
    displayGrid(grid);

    while (true)
    {
        checkAll(grid);
        displayGrid(grid);
        int column;
        int number = 2;
        cout << "Enter the column number: ";
        cin >> column;
        column = column - 1;

        for (int i = 0; i <= gridSize - 1; i++)
        {

            if (grid[i][column] == 0 || grid[i][column] == number)
            {
                grid[i][column] = grid[i][column] + number;
                columnCheck(grid, i, column);
                displayGrid(grid);
                break;
            }

            columnCheck(grid, i, column);
            rowCheck(grid, i, column);
            checkAll(grid);
            displayGrid(grid);
        }
    }
    return 0;
}