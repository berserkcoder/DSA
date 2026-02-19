class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size() <= 1) return 0;
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        int ind = 0;
        int i = 0;
        while(i < s.size()-1){
            count2 = count1;
            count1 = 0;
            ind = i;
            while(i<s.size()-1 && s[i] == s[i+1]){
                i++;
            }
            count1 = i - ind + 1;
            ans += min(count1,count2);
            i++;
        }
        if(s[s.size()-1] != s[s.size()-2]) ans++;
        return ans;
    }
};