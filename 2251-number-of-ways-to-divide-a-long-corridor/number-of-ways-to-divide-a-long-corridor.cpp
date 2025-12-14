class Solution {
public:
    int numberOfWays(string corridor) {
        long long ans = 0;
        int s = 0;
        for(int i = 0;i<corridor.size();i++){
            if(corridor[i] == 'S') s++;
        }
        if(s % 2 == 1 || s == 0) return ans;
        int seat = 0;
        long long count = 0;
        ans = 1;
        for(int i = 0;i<corridor.size();i++){
            if(corridor[i] == 'S') {
                ans = (ans * (count+1)) % 1000000007;
                count = 0;
                seat++;
            }
            else if(seat % 2 == 0 && seat != 0) {
                count++;
            }
            else if(seat == s-1) break;
        }
        return ans;
    }
};