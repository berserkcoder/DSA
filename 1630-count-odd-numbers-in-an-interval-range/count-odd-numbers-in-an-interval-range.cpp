class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        if(low % 2 == 1) {
            low++;
            ans++;
        }
        if(high % 2 == 1) {
            high--;
            ans++;
        }
        ans += (high-low)/2;
        return ans;
    }
};