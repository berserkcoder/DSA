class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int temp = start;
        while(temp < nums.size()){
            if(nums[temp] == target) {
                ans = min(ans,abs(temp-start));
                break;
            }
            temp++;
        }
        temp = start;
        while(temp >= 0){
            if(nums[temp] == target) {
                ans = min(ans,abs(temp-start));
                break;
            }
            temp--;
        }
        return ans;
    }
};