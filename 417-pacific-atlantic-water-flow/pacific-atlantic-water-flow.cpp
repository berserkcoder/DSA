// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         vector<vector<int>> ans;
//         for(int i = 0;i<heights.size();i++){
//             for(int j = 0;j<heights[i].size();j++){
//                 vector<vector<int>> vis(heights.size(),vector<int>(heights[0].size(),0));
//                 bool pacific = check(i,j,heights,0,0,vis);
//                 vector<vector<int>> vis1(heights.size(),vector<int>(heights[0].size(),0));
//                 bool atlantic = check(i,j,heights,heights.size()-1,heights[i].size()-1,vis1);
//                 if(pacific && atlantic) ans.push_back({i,j});
//             }
//         }
//         return ans;
//     }
//     bool check(int row,int col,vector<vector<int>>& heights,int targetRow,int targetCol,vector<vector<int>>& vis){
//         priority_queue<pair<int,int>> pq;
//         pq.push({row,col});
//         while(!pq.empty()){
//             int r = pq.top().first;
//             int c = pq.top().second;
//             pq.pop();
//             vis[r][c] = 1;
//             if(r == targetRow || c == targetCol) return true;
//             if(r > 0 && heights[r-1][c] <= heights[r][c] && vis[r-1][c] == 0) pq.push({r-1,c});
//             if(c > 0 && heights[r][c-1] <= heights[r][c] && vis[r][c-1] == 0) pq.push({r,c-1});
//             if(r < heights.size()-1 && heights[r+1][c] <= heights[r][c] && vis[r+1][c] == 0) pq.push({r+1,c});
//             if(c < heights[0].size()-1 && heights[r][c+1] <= heights[r][c] && vis[r][c+1] == 0) pq.push({r,c+1});
//         }
//         return false;
//     }
// };

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pac(n,vector<int> (m,0));
        vector<vector<int>> at(n,vector<int> (m,0));
        queue<pair<int,int>> pq,aq;
        for(int i = 0;i< n;i++){
            pq.push({i,0});
            pac[i][0] = 1;
            aq.push({i,m-1});
            at[i][m-1] = 1;
        }
        for(int i = 0;i< m;i++){
            pq.push({0,i});
            pac[0][i] = 1;
            aq.push({n-1,i});
            at[n-1][i] = 1;
        }
        bfs(heights,pq,pac);
        bfs(heights,aq,at);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pac[i][j] && at[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& h, queue<pair<int,int>>& q, vector<vector<int>>& vis) {
        int m = h.size(), n = h[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            for(auto& d: dirs){
                int nr = r + d[0], nc = c + d[1];
                
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(vis[nr][nc]) continue;
                if(h[nr][nc] < h[r][c]) continue; // reverse flow: go uphill only
                
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }
};