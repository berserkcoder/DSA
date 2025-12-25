class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1]; 
        });
        for(int i = boxTypes.size()-1;i>=0;i--){
            if(boxTypes[i][0] >= truckSize) {
                ans += truckSize * boxTypes[i][1];
                break;
            }
            ans += boxTypes[i][0] * boxTypes[i][1];
            truckSize = truckSize - boxTypes[i][0];
            cout << truckSize << " ";
        }
        return ans;
    }
};