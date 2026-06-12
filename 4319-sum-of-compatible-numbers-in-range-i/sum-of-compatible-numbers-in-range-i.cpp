class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        for(int i = 0;i<=10000;i++){
            if(abs(n-i) <= k && (n&i) == 0) {
                ans += i;
                cout << i << " ";
            }
        }
        return ans;
    }
};