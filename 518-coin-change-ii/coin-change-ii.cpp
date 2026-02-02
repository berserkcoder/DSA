class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = recur(n-1,amount,coins,dp);
        return ans;
    }
    int recur(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0 || ind < 0) {
            if(amount != 0) return 0;
            return 1;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        if(amount >= coins[ind]) return dp[ind][amount] = recur(ind,amount-coins[ind],coins,dp) + recur(ind-1,amount,coins,dp);
        return dp[ind][amount] = recur(ind-1,amount,coins,dp);
    }
};