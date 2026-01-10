class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        if(n <= 1) return n;
        bool flag = true;
        int previous = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(ans == 1){
                if(previous == nums[i]) continue;
                else if(nums[i] < previous) flag = false;
                previous = nums[i];
                ans++;
            }else {
                if(flag){
                    if(nums[i] < previous){
                        previous = nums[i];
                        flag = !flag;
                        ans++;
                    }
                    if(nums[i] > previous )previous = nums[i];
                }else {
                    if(nums[i] > previous){
                        previous = nums[i];
                        flag = !flag;
                        ans++;
                    }
                    if(nums[i] < previous )previous = nums[i];
                }
            }
        }
        return ans;
    }
};