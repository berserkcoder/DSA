class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> ans;
        map<int,int> mpp;
        for(int i = 1;i<= 1000;i++){
            for(int j = i;j<=1000;j++){
                int val = (i*i*i) + (j*j*j);
                if(val <= n)mpp[val]++;
            }
        }
        for(auto it : mpp){
            if(it.second >= 2) ans.push_back(it.first);
        }
        return ans;
    }
};