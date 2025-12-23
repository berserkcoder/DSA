class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;
        int boundary = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(boundary == 0) ans++;
            boundary += nums[i];
        }
        if(boundary == 0) ans++;
        return ans;
    }
};