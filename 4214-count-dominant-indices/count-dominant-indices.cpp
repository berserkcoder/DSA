class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        vector<double> prefix(nums.size());
        prefix[0] = 0;
        int sum = 0;
        int ans = 0;
        for(int i = nums.size()-1;i>=1;i--){
            sum += nums[i];
            double avg = (double)sum / (double)(nums.size()-i);
            prefix[i] = avg;
        }
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i] > prefix[i+1]) ans++;
        }
        return ans;
    }
};