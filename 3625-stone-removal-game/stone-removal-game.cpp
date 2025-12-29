class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;
        bool ans = false;
        while(n > 0) {
            if(i > n) return ans;
            n = n-i;
            i--;
            ans = !ans;
        }
        return ans;
    }
};