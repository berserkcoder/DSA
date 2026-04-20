class Solution {
public:
    static bool comp(string& s1,string& s2){
        return s1.size() < s2.size();
    }
    bool checkPossible(string& s1,string& s2){
        if(s1.size() != s2.size()+1) return false;
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()){
            if(s1[i] == s2[j]) {
                i++;
                j++;
            }else i++;
        }
        return j == s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(), comp);
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = n-1;i>=0;i--){
            for(int prev = i-1;prev>=-1;prev--){
                int len = dp[i+1][prev+1];
                if(prev == -1 || checkPossible(words[i],words[prev])){
                    len = max(1 + dp[i+1][i+1],len);
                }
                dp[i][prev+1] = len;
            }
        }
        return dp[0][0];
    }
};