class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int currentCapacity = capacity;
        for(int i = 0;i<plants.size();i++){
            if(currentCapacity >= plants[i]){
                ans++;
                currentCapacity -= plants[i];
            }else {
                currentCapacity = capacity;
                ans += (i)*2+1;
                currentCapacity -= plants[i];
            }
            cout << ans << endl;
        }
        return ans;
    }
};