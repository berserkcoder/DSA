class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> ans;
        vector<int> index(nums.size());
        vector<long long> prefixSum(nums.size());
        int count = 1;
        prefixSum[0] = count;
        for(int i = 1;i<nums.size();i++){
            if(nums[i] >= nums[i-1]) count++;
            else count = 1;
            prefixSum[i] = count + prefixSum[i-1];
        }
        index[nums.size()-1] = nums.size()-1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] <= nums[i+1]) index[i] = index[i+1];
            else index[i] = i;
        }
        for(int i = 0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            long long val = 0;
            int b = index[left];
            long long sequence = b-left+1;
            if(b<=right) {
                val += (sequence*(sequence+1))/2;
                val += (prefixSum[right] - prefixSum[b]);
            }
            else {
                sequence = right-left+1;
                val += (sequence*(sequence+1))/2;
            }
            
            ans.push_back(val);
        }
        return ans;
    }
};