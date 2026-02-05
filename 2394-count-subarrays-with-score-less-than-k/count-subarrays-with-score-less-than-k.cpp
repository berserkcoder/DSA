class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long l = 0;
        long long r = 0;
        long long n = nums.size();
        long long sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum * (r-l+1) >= k){
                sum -= nums[l];
                l++;
            }
            if(sum * (r-l+1) < k) ans += r-l+1;
            r++;
        }
        return ans;
    }
};