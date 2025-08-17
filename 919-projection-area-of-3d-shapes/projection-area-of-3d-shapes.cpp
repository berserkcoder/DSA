class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int above = grid.size() * grid[0].size();
        int left = 0;
        int maxleft = -1;
        int maxright = -1;
        int right = 0;
        int count = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 0) count++;
                if(maxleft < grid[i][j]) maxleft = grid[i][j];
                if(maxright < grid[j][i]) maxright = grid[j][i];
            }
            left += maxleft;
            right += maxright;
            maxleft = -1;
            maxright = -1;
        }
        int ans = left + right + above - count;
        return ans;
    }
};