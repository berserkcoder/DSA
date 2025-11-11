class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = 0;
        for(int i = 0;i<nums.size();i++){
            if(m < nums[i]) m = nums[i];
        }
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans += m - nums[i];
        }
        return ans;
    }
};