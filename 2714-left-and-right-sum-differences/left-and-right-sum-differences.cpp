class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left(nums.size(),0);
        vector<int> right(nums.size(),0);
        vector<int> ans;
        int sum = 0;
        int sum1 = 0;
        for(int i = 0;i<nums.size();i++){
            left[i] = sum;
            right[nums.size()-i-1] = sum1;
            sum += nums[i];
            sum1 += nums[nums.size()-i-1];
        }
        for(int i = 0;i<nums.size();i++){
            ans.push_back(abs(left[i]-right[i]));
        }
        return ans;
    }
};