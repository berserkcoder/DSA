class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n+1,1);
        for(int i = 2;i<=n;i++){
            if(i != n && s[i] == '0' && s[i-1] == '0') return 0;
            if(i != n && s[i] == '0'){
                dp[i] = dp[i-1];
            }
            else if(s[i-1] == '0' && s[i-2] > '2') return 0;
            else if(s[i-1] == '0') dp[i] = dp[i-1];
            else if(s[i-2] == '1') dp[i] = dp[i-1] + dp[i-2];
            else if(s[i-2] == '2' && s[i-1] < '7') dp[i] = dp[i-1] + dp[i-2];
            else dp[i] = dp[i-1];
        }
        for(int i = 1;i<=n;i++) cout << dp[i] << " ";
        return dp[n];
    }
};