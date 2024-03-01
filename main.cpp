#include <iostream>
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
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            cout << grid[i][j] << "   ";
        }
        cout << endl;
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
        cout << "Select A Column : ";
        cin >> column;
        column = column - 1;
        for (int i = 0; i <= gridSize - 1; i++)
        {
            if (grid[i][column] == 0 || grid[i][column] == number)
            {
                grid[i][column] = grid[i][column] + number;
                break;
            }
        }
        displayGrid(grid);
    }
    return 0;
}