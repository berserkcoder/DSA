class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> zero(3,0);
        vector<int> one(3,0);
        vector<int> two(3,0);
        for(int i = 0;i<nums.size();i++){
            int rem = nums[i] % 3;
            if(rem == 0){
                if(nums[i] > zero[0]) zero[0] = nums[i];
                sort(zero.begin(),zero.end());
            }else if(rem == 1){
                if(nums[i] > one[0]) one[0] = nums[i];
                sort(one.begin(),one.end());
            }else {
                if(nums[i] > two[0]) two[0] = nums[i];
                sort(two.begin(),two.end());
            }
        }
        // int ans = 0;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        int sum4 = zero[2] + one[2] + two[2];
        for(int i = 0;i<=2;i++){
            if(zero[2] == 0) sum4 = 0; 
            sum1 += zero[i];
            if(zero[i] == 0) {
                sum1 = 0;
                break;
            }
        }
        for(int i = 0;i<=2;i++){
            if(one[2] == 0) sum4 = 0; 
            sum2 += one[i];
            if(one[i] == 0) {
                sum2 = 0;
                break;
            }
        }
        for(int i = 0;i<=2;i++){
            if(two[2] == 0) sum4 = 0; 
            sum3 += two[i];
            if(two[i] == 0) {
                sum3 = 0;
                break;
            }
        }
        int ans = max(sum1,max(sum2,max(sum3,sum4)));
        if(ans % 3 != 0) return 0;
        return ans;
    }
};