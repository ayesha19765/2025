class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price encountered so far to the first day's price
        int minprice = prices[0];

        // Initialize the maximum profit to 0 (no profit at the beginning)
        int ans = 0;

        // Iterate through the array starting from the second day
        for(int i = 1; i < prices.size(); i++) {
            // Update the maximum profit if selling on day i gives a better result
            ans = max(ans, prices[i] - minprice);

            // Update the minimum price encountered so far
            minprice = min(minprice, prices[i]);
        }

        // Return the maximum profit calculated
        return ans;
    }
};

/*
Time Complexity:
- O(n): We iterate through the `prices` array once, where `n` is the number of days.

Space Complexity:
- O(1): We use only a constant amount of extra space (variables `minprice` and `ans`).
*/
