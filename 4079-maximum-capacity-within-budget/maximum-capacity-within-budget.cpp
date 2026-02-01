class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        int ans = 0;

        // store (cost, capacity)
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({costs[i], capacity[i]});
        }

        // sort by cost
        sort(v.begin(), v.end());

        // prefix best and second-best capacities
        vector<int> best1(n), best2(n);
        best1[0] = v[0].second;
        best2[0] = -1;

        for (int i = 1; i < n; i++) {
            if (v[i].second > best1[i - 1]) {
                best2[i] = best1[i - 1];
                best1[i] = v[i].second;
            } else {
                best1[i] = best1[i - 1];
                best2[i] = max(best2[i - 1], v[i].second);
            }
        }

        // case 1: choose only one machine
        for (int i = 0; i < n; i++) {
            if (v[i].first < budget)
                ans = max(ans, v[i].second);
        }

        // case 2: choose two distinct machines
        for (int i = 0; i < n; i++) {
            int remaining = budget - v[i].first - 1; // strictly less

            if (remaining <= 0) continue;

            // largest index j with cost <= remaining
            int j = upper_bound(
                        v.begin(),
                        v.end(),
                        make_pair(remaining, INT_MAX)
                    ) - v.begin() - 1;

            if (j < 0) continue;

            // pick best capacity excluding i
            int best;
            if (best1[j] != v[i].second) {
                best = best1[j];
            } else {
                best = best2[j];
            }

            if (best != -1) {
                ans = max(ans, v[i].second + best);
            }
        }

        return ans;
    }
};
