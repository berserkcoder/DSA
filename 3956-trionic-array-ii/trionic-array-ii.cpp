class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(4,-1e17));
        for(int i = 1;i<=n;i++){
            dp[i][0] = nums[i-1];
        }
        long long ans = -1e17;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<=3;j++){
                if((j == 1 || j == 3)  && nums[i-1] > nums[i-2]){
                    dp[i][j] = max(nums[i-1] + dp[i-1][j-1],nums[i-1] + dp[i-1][j]);
                    if(j==3) ans = max(ans,dp[i][j]);
                }
                if(j == 2 && nums[i-1] < nums[i-2]){
                    dp[i][j] = max(nums[i-1] + dp[i-1][j-1],nums[i-1] + dp[i-1][j]);
                }
            }
        }
        return ans;
    }
};