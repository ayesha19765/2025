class Solution
{
public:
bool solveSpaceOpt(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0);
    vector<bool> dp(k + 1, 0);
    dp[0] = 1;
    prev[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[j] = prev[j] || (j >= arr[i] ? prev[j - arr[i]] : 0);
        }
        prev = dp;
    }
    return dp[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solveSpaceOpt(n, k, arr);
}
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2)
            return 0;
        return subsetSumToK(nums.size(), sum / 2, nums);
    }
};