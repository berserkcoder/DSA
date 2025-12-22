class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> pq;
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(s[i] == '0') pq.push(nums[i]);
            else {
                int val = nums[i];
                if(!pq.empty() && pq.top() > nums[i]){
                    val = pq.top();
                    pq.pop();
                    pq.push(nums[i]);
                }
                ans += val;
            }
        }
        return ans;
    }
};