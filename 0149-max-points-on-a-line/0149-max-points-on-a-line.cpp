class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n; // If there are 2 or fewer points, all are on the same line.

        int ans = 0; // Stores the maximum number of points on a single line.

        for (int i = 0; i < n; i++) {
            // Current point coordinates
            int x1 = points[i][0], y1 = points[i][1];

            // To track slopes and their counts
            unordered_map<double, int> cnt;

            // Count for vertical lines (same x-coordinates)
            int vertical = 0;

            // Iterate through all points after the current point `i`
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 == x2) {
                    // If the x-coordinates are the same, it's a vertical line
                    vertical++;
                } else {
                    // Calculate the slope
                    double slope = ((y2 - y1) * 1.0) / (x2 - x1);
                    cnt[slope]++; // Increment the count for this slope
                }
            }

            // Update the maximum points on a line passing through point `i`
            for (auto& [slope, count] : cnt) {
                ans = max(ans, count);
            }

            // Also consider the vertical line case
            ans = max(ans, vertical);
        }

        return ans + 1; // Include the current point itself.
    }
};

/*
### Explanation:
1. **Base Case**:
   - If there are 2 or fewer points, all points lie on the same line, so return `n`.

2. **Iterating Over Points**:
   - For each point `i`, calculate the slope of the line formed with every other point `j`.
   - Use a hashmap `cnt` to store the count of points for each unique slope.
   - Maintain a separate `vertical` count for points forming vertical lines with point `i`.

3. **Calculate Maximum Points for Each Point**:
   - Traverse the hashmap `cnt` to find the maximum count of points with the same slope.
   - Compare this with the count of vertical lines to handle vertical cases.

4. **Include Current Point**:
   - Add `1` to the maximum count (to include the current point itself).

### Time Complexity:
- **O(n²)**:
  - Outer loop runs 
*/