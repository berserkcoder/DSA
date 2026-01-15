class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int ans = 0;
        if (k == 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (mpp[nums[i]] >= 2)
                    ans++;
                mpp.erase(nums[i]);
            }
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (mpp.find(nums[i]) != mpp.end()) {
                    if (mpp.find(nums[i] + k) != mpp.end())
                        ans++;
                    if (mpp.find(nums[i] - k) != mpp.end())
                        ans++;
                }
                mpp.erase(nums[i]);
            }
        }
        return ans;
    }
};