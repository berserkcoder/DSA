class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int> mpp;
        mpp[0] = 1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < 0) sum = (sum + k+(nums[i]%k)) % k;
            else sum = (sum + nums[i]%k) % k;
            ans += mpp[sum];
            mpp[sum]++;
        }
        return ans;
    }
};