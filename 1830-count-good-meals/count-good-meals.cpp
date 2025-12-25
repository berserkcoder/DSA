class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int ans = 0;
        sort(deliciousness.begin(),deliciousness.end());
        map<int,int> mpp;
        mpp[deliciousness[0]]++;
        for(int i = 1;i<deliciousness.size();i++){
            long long nextGoodMeal = nextPowerOfTwo(deliciousness[i]);
            if(nextGoodMeal - deliciousness[i] == 0) ans = (ans + mpp[deliciousness[i]]) % 1000000007;
            ans = (ans + mpp[nextGoodMeal - deliciousness[i]]) % 1000000007;
            cout << ans << " ";
            mpp[deliciousness[i]]++;
        }
        return ans;
    }
    long long nextPowerOfTwo(int n){
        long long i = 1;
        while(i<n){
            i *= 2;
        }
        return i;
    }
};