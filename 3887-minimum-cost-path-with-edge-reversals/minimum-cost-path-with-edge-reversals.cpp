class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        int ans = 1e9;
        vector<int> vis(n,0);
        vector<vector<vector<int>>> graph(n);
        for(int i = 0;i< edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],2*edges[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top()[1];
            int cost = pq.top()[0];
            pq.pop();
            if(cost >= ans) continue;
            if(vis[node] == 1) continue;
            vis[node] = 1;
            if(node == n-1) {
                ans = min(ans,cost);
            }
            for(vector<int> it : graph[node]){
                if(vis[it[0]] == 0){
                    pq.push({cost+it[1],it[0]});
                }
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};