class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, maxlen = 0;
        int zero = 0;
        while(r<nums.size()){
            if(nums[r] != 1) zero++;
            if(zero>1){
                if(nums[l] != 1) zero--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen-1;
    }
};