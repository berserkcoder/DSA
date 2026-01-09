class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        bool take = true;
        bool lr = true;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++){
            if(lr){
                for(int j = 0;j<m;j++){
                    if(take) ans.push_back(grid[i][j]);
                    take = !take;
                }
            }else {
                for(int j = m-1;j>=0;j--){
                    if(take) ans.push_back(grid[i][j]);
                    take = !take;
                }
            }
            lr = !lr;
        }
        return ans;
    }
};