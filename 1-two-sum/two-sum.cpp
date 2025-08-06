class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int,int> mpp;
        for(int i = 0;i < nums.size();i++){
            int rem = target-nums[i];
            if(mpp.find(rem) != mpp.end() && mpp[rem] != i){
                ans[0] = mpp[rem];
                ans[1] = i;
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};