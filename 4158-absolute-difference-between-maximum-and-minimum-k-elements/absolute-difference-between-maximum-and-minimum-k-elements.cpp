class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int largest = 0;
        int smallest = 0;
        for(int i = 0;i<k;i++){
            largest += nums[nums.size()-i-1];
            smallest += nums[i];
        }
        return abs(largest - smallest);
    }
};