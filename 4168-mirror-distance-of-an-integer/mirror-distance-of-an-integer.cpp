class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int val = n;
        while(val != 0){
            int digit = val % 10;
            val = val/10;
            rev = rev * 10 + digit;
        }
        return abs(n - rev);
    }
};