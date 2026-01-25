class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int index = 0;
        for(int i = nums.size()-1;i > 0;i--){
            if(nums[i] <= nums[i-1]){
                index = i;
                break;
            }
        }
        // if(index == -1) return 0;
        return index;
    }
};