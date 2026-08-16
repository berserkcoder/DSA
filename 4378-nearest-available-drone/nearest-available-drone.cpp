class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ans = -1;
        int md = INT_MAX;
        for(int i = 0;i<drones.size();i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int d = drones[i][2];
            int m = 0;
            m += abs(target[0] - x);
            m += abs(target[1] - y);
            if(m <= d){
                if(md > m) {
                    ans = i;
                    md = m;
                }
            }
        }
        return ans;
    }
};