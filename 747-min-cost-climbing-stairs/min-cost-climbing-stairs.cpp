class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int onestep = cost[0];
        int twostep = cost[1];
        for(int i = 2;i<n;i++){
            int temp = twostep;
            twostep = cost[i] + min(onestep,twostep);
            onestep = temp;
        }
        return min(onestep,twostep);
    }
};