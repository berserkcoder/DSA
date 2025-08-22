class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int start = -1;
        int end = -1;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 1 && start == -1){
                    start = i;
                    end = i;
                }else if(grid[i][j] == 1){
                    end = i;
                }
            }
        }
        int row = end - start + 1;
        start = -1;
        end = -1;
        for(int i = 0;i<grid[0].size();i++){
            for(int j = 0;j<grid.size();j++){
                if(grid[j][i] == 1 && start == -1){
                    start = i;
                    end = i;
                }else if(grid[j][i] == 1){
                    end = i;
                }
            }
        }
        int col = end-start+1;
        // cout << row << " " << col << endl;
        return row*col;
    }
};