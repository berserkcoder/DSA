class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[i].size();j++){
                bool ans = false;
                if(board[i][j] == word[0]) ans = check(i,j,board,word,vis,1);
                if(ans == true) return true;
            }
        }
        return false;
    }
    bool check(int r,int c,vector<vector<char>>& board, string word,vector<vector<int>>& vis,int l){
        if(l == word.size()) return true;
        vis[r][c] = 1;
        if(r > 0 && board[r-1][c] == word[l]  && vis[r-1][c] == 0)  if(check(r-1,c,board,word,vis,l+1)) return true;
        if(c > 0 && board[r][c-1] == word[l] && vis[r][c-1] == 0)  if(check(r,c-1,board,word,vis,l+1)) return true;
        if(r < board.size()-1 && board[r+1][c] == word[l] && vis[r+1][c] == 0)  if(check(r+1,c,board,word,vis,l+1)) return true;
        if(c < board[0].size()-1 && board[r][c+1] == word[l] && vis[r][c+1] == 0)  if(check(r,c+1,board,word,vis,l+1)) return true;
        vis[r][c] = 0;
        return false;
    }
};