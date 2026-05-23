class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 1;
        if(nums[0] < nums[nums.size()-1]) c--;
        for(int i = 1;i< nums.size();i++){
            if(nums[i] < nums[i-1]){
                if(c == 0)return false;
                c--;
            }
        }
        return true;
    }
};