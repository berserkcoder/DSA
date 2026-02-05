class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int index = i + nums[i];
            while (index < 0){
                index = index + nums.size();
            }
            if (index >= nums.size())
                index = index % nums.size();
            
            ans[i] = nums[index];
        }
        return ans;
    }
};