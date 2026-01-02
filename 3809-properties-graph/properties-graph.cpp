class Solution {
public:
    int intersect(const vector<int>& A, const vector<int>& B) {
        bool f1[101] = {}, f2[101] = {};
        for(const int& a : A)
            f1[a] = 1;
        for(const int& b : B)
            f2[b] = 1;
        int res = 0;
        for(int i = 1; i <= 100; ++i)
            res += f1[i] && f2[i];
        return res;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(intersect(properties[i], properties[j]) >= k) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int res = 0;
        vector<int> vis(101,0);
        for(int i = 0; i < n; ++i) {
            if(vis[i])
                continue;
            queue<int> q{{i}};
            vis[i] = 1;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int v : adj[u]) 
                    if(!vis[v])
                        q.push(v), vis[v] = 1;
            }
            res += 1;
        }
        return res;
    }
};