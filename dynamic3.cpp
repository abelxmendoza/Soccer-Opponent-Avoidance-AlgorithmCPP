#include <iostream>
#include <vector>

using namespace std;

// This program computes the number of unique paths from the top-left
// corner to the bottom-right corner of a grid, where certain cells
// are blocked and cannot be traversed.

int main() {
    int r = 8, c = 9;

    // Initialize the grid with some blocked and unblocked cells.
    vector<vector<char>> grid = {
        {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', '.', '.', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    // If the starting or ending cell is blocked, there are no possible paths.
    if (grid[0][0] == 'X' || grid[r - 1][c - 1] == 'X') {
        cout << "0\n";
        return 0;
    }

    // Initialize a 2D dynamic programming table to store the number of paths to each cell.
    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[0][0] = 1;

    // Fill in the first column of the table.
    for (int i = 1; i < r; i++) {
        if (grid[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill in the first row of the table.
    for (int j = 1; j < c; j++) {
        if (grid[0][j] == '.') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill in the rest of the table by summing the paths from the cell above and to the left,
    // unless the current cell is blocked, in which case it has no paths.
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    // Output the final result, which is the number of unique paths to the bottom-right cell.
    cout << dp[r - 1][c - 1] << "\n";
    return 0;
}

