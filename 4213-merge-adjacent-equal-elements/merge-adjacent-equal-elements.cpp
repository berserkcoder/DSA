class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> q;
        long long temp = (long long)nums[0];
        q.push(temp);
        for(int i = 1;i<nums.size();i++){
            long long val = (long long)nums[i];
            while(!q.empty() && q.top() == val){
                val += val;
                q.pop();
            }
            q.push(val);
        }
        vector<long long> ans(q.size());
        int i = q.size()-1;
        while(!q.empty()){
            ans[i] = q.top();
            q.pop();
            i--;
        }
        return ans;
    }
};