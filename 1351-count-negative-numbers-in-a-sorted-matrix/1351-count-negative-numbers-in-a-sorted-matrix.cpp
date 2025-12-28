class Solution {
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int row = m - 1;
        int col = 0;
        while (row >= 0 && col < n)
        {
            if (grid[row][col] < 0)
            {
                count += n - col;
                row--;
            }
            else
                col++;
        }
        return count;
    }
};
/*
Approach:
    The grid is sorted row-wise and column-wise in non-increasing order (i.e., numbers decrease as you move to the right or up).
    Start from the bottom-left corner (the largest number in the last column).
    If a number is negative, all numbers to its right in the same row are also negative, so we count them and move up a row.
    If the number is non-negative, move right to check the next column.
    This minimizes the number of elements we need to check.
Time Complexity:
    The algorithm runs in O(m + n), where m is the number of rows and n is the number of columns.
    We either move up or right in each step, so the total number of steps is bounded by the dimensions of the grid.
Space Complexity:
    The algorithm uses O(1) extra space.
    We're only using a few variables (count, row, col) to keep track of the position and count, without any additional data structures.
*/