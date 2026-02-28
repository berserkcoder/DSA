class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 1;
        long long mod = 1e9 + 7;
        for(long long i = 2;i<=n;i++){
            long long val = 1;
            while(i >= pow(2,val)){
                val++;
            }
            ans = (ans << val) % mod;
            ans = (ans + i) % mod;
        }
        return ans;
    }
};