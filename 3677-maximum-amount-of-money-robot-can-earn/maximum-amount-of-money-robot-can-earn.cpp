class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(3,-1e8)));
        dp[1][1][0] = coins[0][0];
        if(coins[0][0] < 0) {
            dp[1][1][1] = 0;
            dp[1][1][2] = 0;
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(i == 1 && j == 1) continue;
                for(int k = 0;k<=2;k++){
                    dp[i][j][k] = coins[i-1][j-1] + max(dp[i-1][j][k],dp[i][j-1][k]);
                    if(k>0 && coins[i-1][j-1] < 0){
                        dp[i][j][k] = max(dp[i-1][j][k-1],max(dp[i][j-1][k-1],dp[i][j][k]));
                    }
                }
            }
        }
        return max(dp[n][m][0],max(dp[n][m][1],dp[n][m][2]));
    }
    // int rec(int row,int col,int k,vector<vector<int>>& coins,vector<vector<vector<int>>>& dp){
    //     if(row < 0 || col < 0) {
    //         if(row < 0 && col != 0) return -1e7;
    //         if(col < 0 && row != 0) return -1e7;
    //         return 0;
    //     }

    //     if(dp[row][col][k] != -1) return dp[row][col][k];

    //     if(k > 0){
    //         if(coins[row][col] >= 0){
    //             return dp[row][col][k] = coins[row][col] + max(rec(row-1,col,k,coins,dp),rec(row,col-1,k,coins,dp));
    //         }else {
    //             return dp[row][col][k] = max({rec(row-1,col,k-1,coins,dp),rec(row,col-1,k-1,coins,dp),coins[row][col] + rec(row-1,col,k,coins,dp),coins[row][col] + rec(row,col-1,k,coins,dp)});
    //         }
    //     }
    //     return dp[row][col][k] = coins[row][col] + max(rec(row-1,col,k,coins,dp),rec(row,col-1,k,coins,dp));
    // }
};