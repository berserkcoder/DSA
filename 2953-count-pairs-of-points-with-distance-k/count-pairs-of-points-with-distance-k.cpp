class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        int ans = 0;
        unordered_map<long long,int> store;
        for(int i = 0;i<=k;i++){
            long long x = i;
            long long y = k-i;
            for(int j = 0;j<n;j++){
                long long a = coordinates[j][0];
                long long b = coordinates[j][1];

                long long key = (a << 32) | b;

                if(store.count(key))
                    ans += store[key];
                long long nx = x ^ a;
                long long ny = y ^ b;
                store[(nx << 32) | ny]++;
            }
            store.clear();
        }
        return ans;
    }
};