class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const long long INF = 1e18;

        // dist[r][c][t] = min cost to reach (r,c) using t teleports
        vector<vector<vector<long long>>> dist(
            m, vector<vector<long long>>(n, vector<long long>(k + 1, INF))
        );

        // Min-heap: {cost, row, col, teleports_used}
        priority_queue<
            tuple<long long,int,int,int>,
            vector<tuple<long long,int,int,int>>,
            greater<>
        > pq;

        dist[0][0][0] = 0;
        pq.push({0, 0, 0, 0});

        // Store all cells sorted by value (for teleport optimization)
        vector<tuple<int,int,int>> cells;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }
        sort(cells.begin(), cells.end());

        // Pointer array: for each teleport count, how many cells processed
        vector<int> ptr(k + 1, 0);

        while (!pq.empty()) {
            auto [cost, r, c, t] = pq.top();
            pq.pop();

            if (cost > dist[r][c][t]) continue;

            // 🎯 Reached destination
            if (r == m - 1 && c == n - 1) {
                return cost;
            }

            // -------- Normal moves --------
            if (r + 1 < m) {
                long long nc = cost + grid[r + 1][c];
                if (nc < dist[r + 1][c][t]) {
                    dist[r + 1][c][t] = nc;
                    pq.push({nc, r + 1, c, t});
                }
            }

            if (c + 1 < n) {
                long long nc = cost + grid[r][c + 1];
                if (nc < dist[r][c + 1][t]) {
                    dist[r][c + 1][t] = nc;
                    pq.push({nc, r, c + 1, t});
                }
            }

            // -------- Teleport moves --------
            if (t < k) {
                // Process all cells with value <= grid[r][c]
                while (ptr[t] < cells.size() &&
                       get<0>(cells[ptr[t]]) <= grid[r][c]) {

                    auto [val, x, y] = cells[ptr[t]];
                    ptr[t]++;

                    if (cost < dist[x][y][t + 1]) {
                        dist[x][y][t + 1] = cost;
                        pq.push({cost, x, y, t + 1});
                    }
                }
            }
        }

        return -1; // Should never happen
    }
};