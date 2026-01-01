class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = moveTime.size()-1;
        int m = moveTime[0].size()-1;
        vector<vector<int>> vis(n+1,vector<int> (m+1,0));
        // pq.push({moveTime[0][0],0,0});
        pq.push({0,0,0});
        vis[0][0] = 1;
        int ans = INT_MAX;
        while(!pq.empty()){
            int val = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            if(row == n && col == m){
                if(ans > val) ans = val;
                return ans;
            }
            if(row > 0 && vis[row-1][col] == 0){
                int time = moveTime[row-1][col];
                time = max(time+1,val+1);
                pq.push({time,row-1,col});
                vis[row-1][col] = 1;
            }
            if(row < n && vis[row+1][col] == 0){
                int time = moveTime[row+1][col];
                time = max(time+1,val+1);
                pq.push({time,row+1,col});
                vis[row+1][col] = 1;
            }
            if(col > 0 && vis[row][col-1] == 0){
                int time = moveTime[row][col-1];
                time = max(time+1,val+1);
                pq.push({time,row,col-1});
                vis[row][col-1] = 1;
            }
            if(col < m && vis[row][col+1] == 0){
                int time = moveTime[row][col+1];
                time = max(time+1,val+1);
                pq.push({time,row,col+1});
                vis[row][col+1] = 1;
            }
        }
        return ans;
    }
};