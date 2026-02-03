class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(20002,-1));
        int ans = recursive(0,nums,-10001,dp);
        return ans;
    }
    int recursive(int ind,vector<int>& nums,int last,vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        if(dp[ind][last+10001] != -1) return dp[ind][last+10001];
        if(nums[ind] > last) return dp[ind][last+10001] = max(1+recursive(ind+1,nums,nums[ind],dp),recursive(ind+1,nums,last,dp));
        return dp[ind][last+10001] = recursive(ind+1,nums,last,dp);
    }
};