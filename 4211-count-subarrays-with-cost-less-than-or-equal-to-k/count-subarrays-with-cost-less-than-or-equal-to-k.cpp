class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long l = 0;
        long long r = 0;
        multiset<long long> s;
        while(r < nums.size()){
            s.insert(nums[r]);
            long long maxElement = *s.rbegin();
            long long minElement = *s.begin();
            long long cost = (maxElement-minElement) * (r-l+1);
            while(l <= r && cost > k){
                auto it = s.find(nums[l]);
                s.erase(it);
                l++;
                if(!s.empty())maxElement = *s.rbegin();
                if(!s.empty())minElement = *s.begin();
                cost = (maxElement-minElement) * (r-l+1);
            }
            if(cost <= k) ans += r-l+1;
            r++;
        }
        return ans;
    }
};