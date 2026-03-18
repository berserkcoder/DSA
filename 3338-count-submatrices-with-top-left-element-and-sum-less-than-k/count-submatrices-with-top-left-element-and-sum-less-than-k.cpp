class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> store(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            int sum = 0;
            for(int j = 1;j<=m;j++){
                sum += grid[i-1][j-1];
                store[i][j] =  sum + store[i-1][j];
                if(store[i][j] <= k) ans++;
                else break;
            }
        }
        return ans;
    }
};