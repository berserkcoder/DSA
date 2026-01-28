class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        vector<int> sums;
        recursion(0,nums,0,sums);
        for(int i = 0;i<sums.size();i++){
            ans += sums[i];
        }
        return ans;
    }
    void recursion(int ind,vector<int>& nums,int sum,vector<int>& sums){
        if(ind >= nums.size()){
            sums.push_back(sum);
            return;
        }
        recursion(ind+1,nums,sum^nums[ind],sums);
        recursion(ind+1,nums,sum,sums);
    }
};