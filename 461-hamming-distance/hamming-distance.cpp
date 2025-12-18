class Solution {
public:
    int hammingDistance(int x, int y) {
        int val1 = x;
        int val2 = y;
        int ans = 0;
        while(val1 != 0 || val2 != 0){
            int digit1 = val1%2;
            val1 = val1/2;
            int digit2 = val2%2;
            val2 = val2/2;
            if(digit1 != digit2) ans++;
        }
        return ans;
    }
};