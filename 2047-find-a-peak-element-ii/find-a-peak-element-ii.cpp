class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> ans;
        for(int i = 0;i<mat.size();i++){
            bool f = false;
            for(int j = 0;j<mat[i].size();j++){
                bool flag = true;
                if(i > 0){
                    if(mat[i][j] <= mat[i-1][j]) flag = false;
                }
                if(i < mat.size()-1){
                    if(mat[i][j] <= mat[i+1][j]) flag = false;
                }
                if(j > 0){
                    if(mat[i][j] <= mat[i][j-1]) flag = false;
                }
                if(j < mat[i].size()-1){
                    if(mat[i][j] <= mat[i][j+1]) flag = false;
                }
                if(flag) {
                    f = true;
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            if(f) break;
        }
        return ans;
    }
};