class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> uniqueElement;
        while(r < nums.size()){
            uniqueElement[nums[r]]++;
            while(uniqueElement[nums[r]] >= 2){
                if(sum > ans) ans = sum;
                uniqueElement[nums[l]]--;
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            r++;
        }
        if(sum > ans) ans = sum;
        return ans;
    }
};