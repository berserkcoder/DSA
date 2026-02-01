class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int smallest = nums[1];
        int secondSmallest = nums[2];
        for(int i = 2;i<nums.size();i++){
            if(nums[i] < smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            }else if(nums[i] < secondSmallest){
                secondSmallest = nums[i];
            }
        }
        ans += smallest;
        ans += secondSmallest;
        return ans;
    }
};