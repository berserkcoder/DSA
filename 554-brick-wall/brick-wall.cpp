class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int i = 0;i<wall.size();i++){
            long long sum = 0;
            for(int j = 0;j<wall[i].size()-1;j++){
                sum += wall[i][j];
                mpp[sum]++;
            }
        }
        for(auto it : mpp){
            if(it.second > ans) ans = it.second;
        }
        return wall.size() - ans;
    }
};