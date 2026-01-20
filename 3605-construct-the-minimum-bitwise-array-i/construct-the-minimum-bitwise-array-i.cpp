class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> store(200000,-1);
        for(int i = 1;i<=1000;i++){
            int val = i | (i+1);
            if(store[val] == -1)store[val] = i;
        }
        for(int i = 0;i<nums.size();i++){
            nums[i] = store[nums[i]];
        }
        return nums;
    }
};