class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 1;
        for(int i = 0;i<n;i++){
            ans = max(ans,palindromeFromCenter(i,i,s));
            ans = max(ans,palindromeFromCenter(i,i+1,s));
        }
        return ans;
    }
    int palindromeFromCenter(int l,int r,string& s){
        int best = 1;
        int n = s.size();   
        while(l>=0 && r<n && s[l] == s[r]){
            l--;
            r++;
        }
        best = max(best,r-l-1);
        // if(l>=0 && r<n){
            best = max(best,isPalindrome(l-1,r,s));
            best = max(best,isPalindrome(l,r+1,s));
        // }
        if(best > n) return best-1;
        return best;
    }
    int isPalindrome(int l,int r,string& s){
        int n = s.size();
        while(l>=0 && r<n && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};