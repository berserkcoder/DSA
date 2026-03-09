class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long long> left(nums.size(),0);
        vector<long long> right(nums.size(),1);
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            left[i] = sum;    
            sum += nums[i];    
        }
        sum = 1;
        for(int i = nums.size()-1;i>=0;i--){
            right[i] = sum;
            long long digits = 0;
            long long val = sum;
            while(val != 0){
                val = val/10;
                digits++;
            }
            digits--;
            val = nums[i];
            while(val != 0){
                val = val/10;
                digits++;
            }
            digits--;
            if(digits >= 15) sum = 1e18;
            else sum *= nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            if(left[i] == right[i]) return i;
        }
        return -1;
    }
};