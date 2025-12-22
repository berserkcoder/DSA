class Solution {
public:
    int mirrorDistance(int n) {
        int val = n;
        int rev = 0;
        while(val!=0){
            int digit = val % 10;
            rev = rev * 10 + digit;
            val = val/10;
        }
        return abs(rev-n);
    }
};