class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int distinct = mpp.size();
        int l = 0;
        int r = 0;
        mpp.clear();
        while(r < n){
            mpp[nums[r]]++;
            while(mpp.size() == distinct) {
                ans += n-r;
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};