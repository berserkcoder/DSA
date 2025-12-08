class Solution {
public:
    int countTriples(int n) {
        int ans = 0 ;
        for(int i = 2;i<= n; i++){
            for(int j = i+1; j<=n; j++){
                double val = sqrt((i*i) + (j*j));
                double intval = (int) val;
                // cout << i << j << endl;
                if(val == intval) {
                    if(intval <= n)ans += 2;
                }
            }
        }
        return ans;
    }
};