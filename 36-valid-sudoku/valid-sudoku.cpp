class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> vis(10,0);
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[i][j] == '.') continue;
                if(vis[board[i][j]-'0'] != 0) return false;
                vis[board[i][j]-'0'] = 1;
            }
            for(int i = 0;i<=9;i++) vis[i] = 0;
        }
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                if(board[j][i] == '.') continue;
                if(vis[board[j][i]-'0'] != 0) return false;
                vis[board[j][i]-'0'] = 1;
            }
            for(int i = 0;i<=9;i++) vis[i] = 0;
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                for(int k = 0;k<3;k++){
                    for(int l = 0;l<3;l++){
                        if(board[3*j + k][3*i + l] == '.') continue;
                        if(vis[board[3*j + k][3*i + l] -'0'] != 0) return false;
                        vis[board[3*j + k][3*i + l] -'0'] = 1;
                    }
                }
                for(int i = 0;i<=9;i++) vis[i] = 0;
            }
        }
        return true;
    }
};