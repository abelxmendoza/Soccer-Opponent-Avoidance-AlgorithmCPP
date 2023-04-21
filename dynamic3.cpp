#include <iostream>
#include <vector>
using namespace std;



int main() {
    int r = 8, c = 9;
    vector<vector<char> > grid = {
        {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', '.', '.', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };

    if (grid[0][0] == 'X' || grid[r - 1][c - 1] == 'X') {
        cout << "0\n";
        return 0;
    }

    vector<vector<int> > dp(r, vector<int>(c, 0));
    dp[0][0] = 1;

    for (int i = 1; i < r; i++) {
        if (grid[i][0] == '.') {
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int j = 1; j < c; j++) {
        if (grid[0][j] == '.') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    cout << dp[r - 1][c - 1] << "\n";
    return 0;
}

