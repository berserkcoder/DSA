class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans = 0;
        int green = 0;
        for(int i = 0;i<lights.size();i++){
            green = max(lights[i],green);
        }
        for(int i = 0;i<arrivalTime.size();i++){
            int val = arrivalTime[i] % period;
            if(val >= green){
                ans = max(ans,period - val);
            }
        }
        return ans;
    }
};