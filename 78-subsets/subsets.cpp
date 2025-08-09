class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> store;
        allSubsets(0,nums.size(),nums,ans,store);
        return ans;
    }
    void allSubsets(int ind,int n,vector<int> &arr,vector<vector<int>>& ans,vector<int>& store){
        if(ind == n){
            ans.push_back(store);
            return;
        }
        store.push_back(arr[ind]);
        allSubsets(ind+1,n,arr,ans,store);
        store.pop_back();
        allSubsets(ind+1,n,arr,ans,store);
    }
};