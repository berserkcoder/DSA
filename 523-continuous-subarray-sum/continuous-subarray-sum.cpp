class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mpp;
        int sum = 0;
        mpp[0] = -1;
        for(int i = 0;i<nums.size();i++){
            sum = (sum + nums[i]%k) %k;
            cout << sum << " ";
            if(mpp.find(sum) == mpp.end()) mpp[sum] = i;
            else {
                if(i - mpp[sum] > 1) return true;
            }
        }
        return false;
    }
};