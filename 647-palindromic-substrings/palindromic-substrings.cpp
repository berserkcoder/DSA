class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            int odd = countPalindrome(i,i,s);
            int even = 0;
            if(i != s.size()-1) even = countPalindrome(i,i+1,s);

            ans += odd;
            ans += even;
        }
        return ans;
    }
    int countPalindrome(int left,int right,string s){
        int val = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            val++;
            left--;
            right++;
        }
        return val;
    }
};