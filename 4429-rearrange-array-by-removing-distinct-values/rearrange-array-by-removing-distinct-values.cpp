class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> count(101,0);
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            count[nums[i]]++;
        }
        bool flag = true;
        while(flag){
            bool change = false;
            for(int i = 1;i<101;i++){
                if(count[i] != 0){
                    count[i]--;
                    ans.push_back(i);
                    change = true;
                }
            }
            if(!change) flag = false;
        }
        return ans;
    }
};