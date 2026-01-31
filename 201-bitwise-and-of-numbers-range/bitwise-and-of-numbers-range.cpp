class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long ans = 0;
        for(int bits = 31;bits >= 0;bits--){
            if(((left & (1 << bits)) & (right & (1 << bits))) != 0) {
                ans += pow(2,bits);
            }
            if(((left & (1 << bits)) ^ (right & (1 << bits))) != 0) {
                break;
            }
        }
        return ans;
    }
};