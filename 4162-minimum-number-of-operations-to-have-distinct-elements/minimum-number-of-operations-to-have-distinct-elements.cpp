class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mpp;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp[nums[r]] == 2){
                ans++;
                for(int i = 0;i<=2;i++){
                    if(l >= nums.size()) return ans;
                    mpp[nums[l]]--;
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};