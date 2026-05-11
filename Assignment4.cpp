#include <iostream>
#include <vector>

using namespace std;

class NQueen
{
    int n;

    vector<string> board;

public:

    // Constructor
    NQueen(int size)
    {
        n = size;

        board.resize(n, string(n, '.'));
    }

    // Check Safe Position
    bool isSafe(int row, int col)
    {
        // Check Upper Column
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // Check Left Diagonal
        for (int i = row - 1,j = col - 1;i >= 0 && j >= 0;i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // Check Right Diagonal
        for (int i = row - 1, j = col + 1;i >= 0 && j < n;i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    // Print Board
    void printBoard()
    {
        for (auto row : board)
        {
            cout << row << endl;
        }

        cout << "-------------------"
             << endl;
    }

    // Backtracking Function
    void solve(int row)
    {
        // Base Case
        if (row == n)
        {
            printBoard();

            return;
        }

        // Try all columns
        for (int col = 0; col < n; col++)
        {
            // Check safe
            if (isSafe(row, col))
            {
                // Place Queen
                board[row][col] = 'Q';

                // Recursive Call
                solve(row + 1);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }
};

int main()
{
    int n = 4;

    NQueen obj(n);

    cout << "Solutions:\n\n";

    obj.solve(0);

    return 0;
}