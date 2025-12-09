class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,long long int> left;
        unordered_map<int,long long int> right;
        long long int ans = 0;
        long long int mod = 1000000007;
        for(int i = 0;i<nums.size();i++){
            right[nums[i]]++;
        }
        for(int i = 0;i<nums.size();i++){
            right[nums[i]]--;
            long target = 2 * nums[i];
            if(left.count(target) && right.count(target) && right[target] > 0){
                ans = (ans + (left[target] * right[target]) % mod) % mod;
            }
            // if(left.find(nums[i]*2) != left.end() && right.find(nums[i]*2) != right.end()){
            //     ans = (ans + (left[target] * right[target]) % mod) % mod;
            // }
            left[nums[i]]++;
        }
        return ans;
    }
};