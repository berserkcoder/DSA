class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans = 0;
        bool andFlag = true;
        for(int bits = 31;bits >= 0;bits--){
            if(((left & (1 << bits)) & (right & (1 << bits))) != 0) {
                andFlag = false;
                ans += pow(2,bits);
            }
            if(((left & (1 << bits)) ^ (right & (1 << bits))) != 0) {
                break;
            }
        }
        if(andFlag) return 0;
        return ans;
    }
};