#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// This function uses an exhaustive search to count the number of valid paths from the top-left to the bottom-right
// of a grid, where the path can only move down or right and cannot pass through obstacles marked with 'X'.

int soccer_avoidance_exhaustive(vector<vector<char> > F) {
    // Determine the dimensions of the grid
    int rows = F.size(), cols = F[0].size();
    // Calculate the total number of moves required to reach the goal post
    int n_moves = rows + cols - 2;
    // Calculate the maximum number of valid paths
    int max_paths = pow(2, n_moves);
    // Initialize the counter for valid paths
    int count_valid_paths = 0;
    // Loop over all possible move sequences
    for (int bits = 0; bits < max_paths; bits++) {
        // Initialize an empty list to hold the current move sequence
        vector<char> candidate_path(n_moves);
        // Convert the binary number to a list of moves
        for (int k = 0; k < n_moves; k++) {
            int bit = (bits >> k) & 1;
            if (bit == 1) {
                candidate_path[k] = 'R';  // move right
            } else {
                candidate_path[k] = 'D';  // move down
            }
        }
        // Check if the candidate path is valid
        int row = 0, col = 0;  // start at the top-left corner
        bool valid_path = true;
        for (int i = 0; i < n_moves; i++) {
            if (candidate_path[i] == 'R') {
                col += 1;  // move right
            } else {
                row += 1;  // move down
            }
            // Check if the new position is valid
            if (row >= rows || col >= cols || F[row][col] == 'X') {
                valid_path = false;
                break;
            }
        }
        // If the candidate path is valid and reaches the bottom-right corner, increment the counter
        if (valid_path && row == rows - 1 && col == cols - 1) {
            count_valid_paths++;
        }
    }
    // Return the number of valid paths
    return count_valid_paths;
}

int main() {
    // Define the grid and obstacles
    vector<vector<char> > field = {
        {'.', '.', '.', '.', '.', '.', 'X', '.', 'X'},
        {'X', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', 'X', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', 'X', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', '.', '.', '.'},
        {'.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}
    };
    // Call the function to count the number of valid paths
    int num_valid_paths = soccer_avoidance_exhaustive(field);
    // Print the result
    cout << "Number of valid paths: " << num_valid_paths << endl;
    return 0;
}
