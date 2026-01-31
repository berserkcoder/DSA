class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bits = 0;bits <= 31;bits++){
            vector<int> tail;
            for(auto x : nums){
                if((x & (1 << bits)) == 0) continue;

                auto it = lower_bound(tail.begin(),tail.end(),x);
                if(it == tail.end()){
                    tail.push_back(x);
                }else *it = x;
            }
            ans = max(ans,(int)tail.size());
        }
        return ans;
    }
};
