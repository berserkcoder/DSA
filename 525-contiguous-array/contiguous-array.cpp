class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        mpp[0] = -1;

        int prefix = 0;
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) prefix--;
            else prefix++;

            if (mpp.count(prefix)) {
                maxlen = max(maxlen, i - mpp[prefix]);
            } else {
                mpp[prefix] = i;
            }
        }
        return maxlen;
    }
};