class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // vector<int> prefix(nums.size());
        int sum = 0;
        map<int,int> mpp;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < 0) sum = (sum + k+(nums[i]%k)) % k;
            else sum = (sum + nums[i]%k) % k;
            if(sum == 0) ans++;
            cout << sum << " ";
            ans += mpp[sum];
            cout << ans << " ";
            // if(sum < 0) {
            //     sum = k + (sum%k);
            //     cout << sum << " "; 
            //     mpp[sum]++;
            // }
            mpp[sum]++;
        }
        return ans;
    }
};