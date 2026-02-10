class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            unordered_map<int,int> odd;
            unordered_map<int,int> even;
            int length = 0;
            for(int j = i;j<n;j++){
                if(nums[j] % 2 == 0) even[nums[j]]++;
                else odd[nums[j]]++;
                if(even.size() == odd.size()) length = j-i+1;
                ans = max(length,ans);
            }
            even.clear();
            odd.clear();
        }
        return ans;
    }
};