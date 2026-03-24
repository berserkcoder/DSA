class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = INT_MAX;
        int even = INT_MAX;
        int n = nums1.size();
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i] % 2 == 1) {
                if(nums1[i] < odd) odd = nums1[i];
            }else{
                if(nums1[i] < even) even = nums1[i];
            }
        }
        if(odd == INT_MAX || even == INT_MAX) return true;
        if(odd < even) return true;
        return false;
    }
};