class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int ans = 0;
        for(int i = 0;i<nums.size()-pattern.size();i++){
            bool flag = true;
            for(int j = 0;j<pattern.size();j++){
                if(pattern[j] == 1 && nums[i+j] >= nums[i+j+1]) flag = false;
                if(pattern[j] == 0 && nums[i+j] != nums[i+j+1]) flag = false;
                if(pattern[j] == -1 && nums[i+j] <= nums[i+j+1]) flag = false;
            }
            if(flag) ans++;
        }
        return ans;
    }
};