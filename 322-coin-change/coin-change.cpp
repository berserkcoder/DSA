class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = recur(n-1,amount,coins,dp);
        if(ans == 1e8) return -1;
        return ans;
    }
    int recur(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind < 0 || amount == 0) {
            if(amount != 0) return 1e8;
            return 0;
        } 
        if(dp[ind][amount] != -1) return dp[ind][amount];
        if(amount >= coins[ind])return dp[ind][amount] = min(1+recur(ind,amount-coins[ind],coins,dp),recur(ind-1,amount,coins,dp));
        return dp[ind][amount] = recur(ind-1,amount,coins,dp);
    }
};