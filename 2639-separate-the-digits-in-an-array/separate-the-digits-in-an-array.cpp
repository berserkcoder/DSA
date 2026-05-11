class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            int rev = 0;
            bool flag = true;
            int zero = 0;
            while(val != 0){
                int digit = val % 10;
                val = val/10;
                if(digit != 0) flag = false;
                if(flag) zero++;
                rev = rev * 10 + digit;
            }
            val = rev;
            while(val!=0){
                int digit = val % 10;
                val = val/10;
                ans.push_back(digit);
            }
            while(zero--){
                ans.push_back(0);
            }
        }
        return ans;
    }
};