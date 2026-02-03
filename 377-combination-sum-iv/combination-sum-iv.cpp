class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, -1);
        return solve(target, nums, dp);
    }
    int solve(int target,vector<int>& nums,vector<long long>& dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        int ans = 0;
        for(int x : nums){
            if(x <= target){
                ans += solve(target-x,nums,dp);
            }
        }
        return dp[target] = ans;
    }
};
