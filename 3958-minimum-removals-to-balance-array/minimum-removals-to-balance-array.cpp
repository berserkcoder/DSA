class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1e9;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            long long val =(long long) (nums[i]) * (long long)(k);
            int index = binarySearch(nums,val);
            if(ans > count+nums.size()-index) ans = count+nums.size()-index;
            count++;
            if(count >= ans) break;
        }
        return ans;
    }
    int binarySearch(vector<int>& arr,long long target){
        int s = 0;
        int e = arr.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid] <= target) {
                s = mid+1;
            }else e = mid-1;
        }
        return s;
    }
};