class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(nums.size());
        int n = nums.size()-1;
        int i = n/2;
        int j = 1;
        while(i >= 0){
            if(j <= nums.size()-1)ans[j] = nums[n];
            ans[j-1] = nums[i];
            j = j+2;
            n--;
            i--;
        }
        for(int ind = 0;ind<nums.size();ind++){
            nums[ind] = ans[ind];
        }
    }
};