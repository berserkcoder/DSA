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
        vector<vector<int>> dp(nums.size(),vector<int>(val+1,0));
        dp[0][0] = (nums[0] == 0 ? 2 : 1);
        if (nums[0] != 0 && nums[0] <= val)
            dp[0][nums[0]] = 1;
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<val+1;j++){
                int take = 0;
                if(j >= nums[i]) take = dp[i-1][j-nums[i]];
                int nottake = dp[i-1][j];
                dp[i][j] = take + nottake;
            }
        }
        return dp[nums.size()-1][val];
        // return sign(nums.size()-1,nums,val,0,dp);
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