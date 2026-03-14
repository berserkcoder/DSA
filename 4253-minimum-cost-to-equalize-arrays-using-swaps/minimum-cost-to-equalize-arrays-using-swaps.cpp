class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> store;
        int n = nums1.size();
        for(int i = 0;i<n;i++){
            store[nums1[i]]++;
            store[nums2[i]]--;
            if(store[nums2[i]] == 0) store.erase(nums2[i]);
        }
        int ans = 0;
        for(auto it : store){
            if(it.second % 2 != 0) return -1;
            if(it.second < 0) ans -= it.second;
            else ans += it.second;
        }
        return ans/4;
    }
};