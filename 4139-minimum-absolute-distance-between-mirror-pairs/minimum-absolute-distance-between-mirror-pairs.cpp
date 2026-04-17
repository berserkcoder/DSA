class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> mpp;
        int ans = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            int rev = 0;
            int val = nums[i];
            while(val != 0){
                int digit = val % 10;
                val = val/10;
                rev = rev*10 + digit;
            }
            if(mpp.find(nums[i]) != mpp.end()){
                ans = min(ans,i - mpp[nums[i]]);
            }
            mpp[rev] = i;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};