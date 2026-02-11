class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mpp;
        vector<vector<string>> ans;
        for(int i = 0;i<strs.size();i++){
            vector<int> hash(26,0);
            for(int j = 0;j<strs[i].size();j++){
                hash[strs[i][j] - 'a']++;
            }
            if(mpp.find(hash) != mpp.end()){
                mpp[hash].push_back(strs[i]);
            }else {
                vector<string> temp;
                temp.push_back(strs[i]);
                mpp.insert({hash,temp});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};