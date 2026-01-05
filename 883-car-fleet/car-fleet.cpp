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
            // cout << store[i][0] << " " << store[i][1] << " " << store[i][2] << endl;
            st.push({store[i][0],store[i][1],store[i][2]});
        }
        // cout << endl;
        int ans = st.size();
        while(!st.empty()){
            // cout << st.top()[0] << " " << st.top()[1] << " " << st.top()[2] << endl;
            st.pop();
        }
        return ans;
    }
    int time(double t,double p,double s){
        double tt = (t-p)/s;
        int itt = tt;
        if(tt > itt) return itt+1;
        return itt;
    }
};