class Solution {
public:
    int minimumK(vector<int>& nums) {
        long long start = 1;
        long long end = INT_MAX;
        int ans = INT_MAX;
        while(start <= end){
            int mid = (start+end)/2;
            if(check(nums,mid)) {
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
    bool check(vector<int>& nums,int mid){
        long long count = 0;
        for(int i = 0;i<nums.size();i++){
            double val = nums[i]/(double)mid;
            int store = nums[i]/mid;
            if(store == val) count += store;
            else count += store+1;
        }
        if(count <= (long long)mid*(long long)mid) return true;
        return false;
    }
};