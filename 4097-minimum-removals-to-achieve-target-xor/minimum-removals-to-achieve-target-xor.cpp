class Solution {
public:
    vector<vector<int>> dp;

    int solve(int ind, int x, vector<int>& nums) {
        if (ind < 0) {
            return (x == 0) ? 0 : INT_MIN;
        }

        if (dp[ind][x] != -1) return dp[ind][x];

        int notTake = solve(ind - 1, x, nums);

        int take = solve(ind - 1, x ^ nums[ind], nums);
        if (take != INT_MIN) take += 1;

        return dp[ind][x] = max(take, notTake);
    }

    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        dp.assign(n, vector<int>(16384, -1));

        int maxSubset = solve(n - 1, target, nums);

        if (maxSubset < 0) return -1;
        return n - maxSubset;
    }
};