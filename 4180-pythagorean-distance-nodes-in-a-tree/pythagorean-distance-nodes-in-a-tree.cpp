class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> distances(n,vector<int>(3,INT_MAX));
        vector<vector<int>> graph(n);
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        bfs(graph,x,distances,0);
        bfs(graph,y,distances,1);
        bfs(graph,z,distances,2);
        int ans = 0;
        for(int i = 0;i<distances.size();i++){
            vector<int> triplet = distances[i];
            sort(triplet.begin(),triplet.end());
            if((long long)triplet[0]*(long long)triplet[0] + (long long)triplet[1]*(long long)triplet[1] == (long long)triplet[2]*(long long)triplet[2]) ans++;
        }
        return ans;
    }
    void bfs(vector<vector<int>>& graph,int source,vector<vector<int>>& distance,int ind){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({source,0});
        vector<int> visited(graph.size(),0);
        visited[source] = 1;
        while(!pq.empty()){
            int node = pq.top()[0];
            int count = pq.top()[1];
            pq.pop();
            if(distance[node][ind] > count) distance[node][ind] = count;
            for(auto& it : graph[node]){
                if(visited[it] == 0){
                    pq.push({it,count+1});
                    visited[it] = 1;
                }
            }
        }
    }
};