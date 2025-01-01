class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check each row
        for (int i = 0; i < 9; i++) {
            int arr[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { // Ignore empty cells
                    int val = board[i][j] - '0';
                    if (arr[val]) return false; // Duplicate found
                    arr[val]++;
                }
            }
        }

        // Check each column
        for (int i = 0; i < 9; i++) {
            int arr[10] = {0};
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') { // Ignore empty cells
                    int val = board[j][i] - '0';
                    if (arr[val]) return false; // Duplicate found
                    arr[val]++;
                }
            }
        }

        // Check each 3x3 sub-grid
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                int arr[10] = {0};
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[row + i][col + j] != '.') { // Ignore empty cells
                            int val = board[row + i][col + j] - '0';
                            if (arr[val]) return false; // Duplicate found
                            arr[val]++;
                        }
                    }
                }
            }
        }

        return true; // All checks passed
    }
};
