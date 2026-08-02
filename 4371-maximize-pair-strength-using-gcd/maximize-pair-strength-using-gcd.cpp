class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                long long val1 = ((long long)nums[i] * (long long)nums[j]);
                long long val2 = (long long)gcd(nums[i],nums[j]);
                if(val1/(val2*val2) > ans) ans = val1/(val2*val2);
            }
        }
        return ans;
    }
};