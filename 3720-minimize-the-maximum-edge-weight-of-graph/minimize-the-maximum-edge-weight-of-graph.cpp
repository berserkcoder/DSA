class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<vector<int>>> graph(n);
        vector<int> vis(n,0);
        vector<int> dis(n,1e8);
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0});
        // vis[0] = 1;
        dis[0] = 0;
        while(!pq.empty()){
            int cost = pq.top()[0];
            int node = pq.top()[1];
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            for(auto it : graph[node]){
                if(dis[it[0]] > it[1]){
                    if(vis[it[0]] == 0){
                        pq.push({max(cost,it[1]),it[0]});
                        dis[it[0]] = min(dis[it[0]] ,max(cost,it[1]));
                    }
                }
            }
            
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(vis[i] == 0) return -1;
            if(dis[i] > ans) ans = dis[i];
        } 
        return ans;
    }
};