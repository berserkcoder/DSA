class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int i = n-1;i>=0;i--){
            for(int buy = 1;buy >= 0;buy--){
                for(int cap = 2;cap >= 0;cap--){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i]+dp[i+1][0][cap],dp[i+1][1][cap]);
                    }else {
                        if(cap > 0)profit = max(prices[i]+dp[i+1][1][cap-1],dp[i+1][0][cap]);
                        else profit == dp[i+1][0][cap];
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        // for(int i = n;i>=0;i--){
        //     for(int buy = 1;buy >= 0;buy--){
        //         for(int cap = 2;cap >= 0;cap--){
        //             cout << dp[i][buy][cap] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        
        return dp[0][1][2];
    }
};