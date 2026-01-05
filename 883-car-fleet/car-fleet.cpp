class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<double>> store;
        for(int i = 0;i<position.size();i++){
            double timeTaken = ((double)target-(double)position[i])/(double)speed[i];
            store.push_back({(double)position[i],(double)speed[i],(double)timeTaken});
        }
        sort(store.begin(),store.end());
        stack<vector<double>> st;
        for(int i = 0;i<position.size();i++){
            while(!st.empty() && st.top()[1] > store[i][1] && st.top()[2] <= store[i][2]){
                st.pop();
            }
            st.push({store[i][0],store[i][1],store[i][2]});
        }
        return st.size();
    }
};