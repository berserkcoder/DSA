class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int i = 0;i<m;i++){
            dp[0][i] = points[0][i];
        }
        for(int i = 1;i<n;i++){
            vector<long long> leftmax(m);
            vector<long long> rightmax(m);
            leftmax[0] = dp[i-1][0];
            rightmax[m-1] = dp[i-1][m-1];
            for(int j = 1;j<m;j++){
                if(dp[i-1][j] > leftmax[j-1]-1) leftmax[j] = dp[i-1][j];
                else leftmax[j] = leftmax[j-1]-1;
                // leftmax[j] = max(dp[i-1][j],leftmax[j-1]-1);
            }
            for(int j = m-2;j>=0;j--){
                if(dp[i-1][j] > rightmax[j+1]-1) rightmax[j] = dp[i-1][j];
                else rightmax[j] = rightmax[j+1]-1;
                // rightmax[j] = max(dp[i-1][j],rightmax[j+1]-1);
            }
            for(int j = 0;j<m;j++){
                long long maxi = 0;
                if(leftmax[j] > rightmax[j]) maxi = leftmax[j];
                else maxi = rightmax[j];
                dp[i][j] = maxi + (long long)points[i][j];
            }
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                cout << points[i][j] << " ";
            }
            cout << endl;
        }
        long long ans = INT_MIN;
        for(int i = 0;i<m;i++){
            ans = max(ans,dp[n-1][i]);
        }
        return ans;
    }
};