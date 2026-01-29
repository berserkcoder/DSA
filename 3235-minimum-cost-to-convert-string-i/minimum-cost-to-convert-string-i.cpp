class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long ans = 0;
        vector<vector<long long>> hash(26,vector<long long>(26,INT_MAX));
        vector<vector<vector<long long>>> graph(26);
        for(int i = 0;i<original.size();i++){
            graph[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        for(int i = 0;i<26;i++){
            priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
            vector<int> vis(26,0);
            pq.push({0,i});
            hash[i][i] = 0;
            while(!pq.empty()){
                int cost = pq.top()[0];
                int alphabet = pq.top()[1];
                pq.pop();
                if(vis[alphabet] == 1) continue;
                vis[alphabet] = 1;
                for(auto it : graph[alphabet]){
                    if(hash[i][it[0]] > cost + it[1]){
                        hash[i][it[0]] = cost + it[1];
                        pq.push({cost+it[1],it[0]});
                    }
                }
            }
            
        }
        for(int i = 0;i<source.size();i++){
            if(source[i] != target[i]){
                if(hash[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
                else {
                    ans += hash[source[i] - 'a'][target[i] - 'a'];
                }
            }   
        }
        return ans;
    }
};