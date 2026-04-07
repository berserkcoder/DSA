class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<long long> even;
        vector<long long> odd;
        long long ans = INT_MAX;

        for(int i = 1;i<n-1;i += 2){
            int remain = max(nums[i-1],nums[i+1]);
            odd.push_back(max(0,remain-nums[i]+1));
        }

        for(int i = 2;i<n-1;i+=2){
            int remain = max(nums[i-1],nums[i+1]);
            even.push_back(max(0,remain-nums[i]+1));
        }

        if(n % 2 == 1){
            return accumulate(odd.begin(),odd.end(), 0LL);
        }

        long long total = 0;
        for(int i = 0;i<even.size();i++) total += even[i];
        ans = total;
        for(int i = 0;i<even.size();i++){
            total -= even[i];
            total += odd[i];

            ans = min(ans,total);
        }

        return ans;
    }
};