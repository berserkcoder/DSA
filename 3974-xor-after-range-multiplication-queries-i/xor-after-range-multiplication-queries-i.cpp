class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans;
        int idx = 0;
        for(int i = 0;i<queries.size();i++){
            idx = queries[i][0];
            while(idx <= queries[i][1]){
                nums[idx] = ((long long)(nums[idx]) * (long long)(queries[i][3])) % (1000000007);
                idx += queries[i][2];
            }
        }
        ans = nums[0];
        for(int i = 1;i< nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};