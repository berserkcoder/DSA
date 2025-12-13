class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0;
        int r = 0;
        while(r<nums.size()-1){
            int rangeMax = r;
            for(int i = l;i<=r;i++){
                rangeMax = max(rangeMax,nums[i]+i);
            }
            jumps++;
            l = r+1;
            r = rangeMax;
        }
        return jumps;
    }
};