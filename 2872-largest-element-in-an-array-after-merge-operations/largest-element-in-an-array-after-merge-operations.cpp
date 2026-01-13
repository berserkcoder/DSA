class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size()-1;
        long long sum = nums[n];
        long long previous = nums[n];
        long long ans = nums[n];
        for(int i = n-1;i>=0;i--){
            if(nums[i]<=previous){
                sum += nums[i];
                previous += nums[i];
            }else {
                if(ans < sum) ans = sum;
                sum = nums[i];
                previous = nums[i];
            }
        }
        if(ans < sum) ans = sum;
        return ans;
    }
};