class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i = 0;i<nums.size();i++){
            vector<int> store;
            store.push_back(nums[i]);
            int l = i+1;
            int h = nums.size()-1;
            while(l < h){
                int sum = nums[l] + nums[h];
                int val = -nums[i];
                if(sum == val){
                    store.push_back(nums[l]);
                    store.push_back(nums[h]);
                    // sort(store.begin(),store.end());
                    st.insert(store);
                    store.pop_back();
                    store.pop_back();
                    l++;
                    h--;
                }
                else if(sum > val){
                    h--;
                }
                else l++;
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};