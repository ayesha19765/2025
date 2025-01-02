class Solution {
public:
    // Helper function to calculate the total time needed to eat bananas at a given speed
    int solve(vector<int>& piles, int n) {
        int cnt = 0;
        for (int i = 0; i < piles.size(); i++) {
            cnt += ceil((piles[i] * 1.0) / n); // Calculate hours needed for each pile
        }
        return cnt; // Return total hours needed
    }

    // Function to determine the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end()); // Set the range of speeds

        // Perform binary search
        while (start < end) {
            int mid = start + (end - start) / 2; // Calculate mid-point speed

            // If the time to eat all piles at speed `mid` is within the limit, reduce the speed
            if (solve(piles, mid) <= h) {
                end = mid;
            }
            // Otherwise, increase the speed
            else {
                start = mid + 1;
            }
        }

        // The minimum speed at which all bananas can be eaten within `h` hours
        return start;
    }
};

/*
Time Complexity:
- O(n * log(maxPile)), where `n` is the number of piles and `maxPile` is the largest pile size.
  Binary search iterates `log(maxPile)` times, and for each iteration, we scan all `n` piles.

Space Complexity:
- O(1), since no additional space is used apart from a few variables.
*/
