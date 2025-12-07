class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans = 0;
        vector<int> leftprefix(nums.size());
        vector<int> rightprefix(nums.size());
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            leftprefix[i] = sum;
        }
        sum = 0;
        for(int i = nums.size()-1; i>=0 ;i--){
            sum += nums[i];
            rightprefix[i] = sum;
        }
        for(int i = 0;i<nums.size()-1;i++){
            if((leftprefix[i] - rightprefix[i+1]) % 2 == 0) ans++;
        }
        return ans;
    }
};