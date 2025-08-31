class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> hash(101,0);
        vector<int> ans;
        for(int i = 0;i<friends.size();i++){
            hash[friends[i]]++;
        }
        for(int i = 0;i<order.size();i++){
            if(hash[order[i]] != 0) ans.push_back(order[i]);
        }
        return ans;
    }
};