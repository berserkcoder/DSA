class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int l = 0;
        int r = k - 1;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }
        while (r < nums.size()) {
            int maxi = *s.rbegin();
            ans.push_back(maxi);
            auto it = s.find(nums[l]);
            s.erase(it);
            l++;
            r++;
            if(r<nums.size()) s.insert(nums[r]);
        }
        return ans;
    }
};