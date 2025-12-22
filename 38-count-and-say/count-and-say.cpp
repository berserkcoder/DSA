class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n == 1) return s;
        for(int i = 2;i<=n;i++){
            s = RLE(s);
        }   
        return s;
    }
    string RLE(string s){
        // int element = s[0];
        int count = 1;
        string ans = "";
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]) count++;
            else {
                ans += to_string(count);
                ans += s[i-1];
                count = 1;
            }
        }
        ans += to_string(count);
        ans += s[s.size()-1];
        // cout << ans << endl;
        return ans;
    }
};