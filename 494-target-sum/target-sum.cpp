class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i = 0;i<nums.size();i++){
            total += nums[i];
        }
        if(abs(target) > total) return 0;
        if((target+total) % 2 != 0) return 0;
        int val = (target+total)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(val+1,-1));
        return sign(nums.size()-1,nums,val,0,dp);
    }
    int sign(int ind,vector<int>& arr,int t,int sum,vector<vector<int>>& dp){
        if(sum > t) return 0;
        if(ind < 0){
            return sum == t;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int plus = sign(ind-1,arr,t,sum+arr[ind],dp);
        int minus = sign(ind-1,arr,t,sum,dp);
        return dp[ind][sum] = plus + minus;
    }
};