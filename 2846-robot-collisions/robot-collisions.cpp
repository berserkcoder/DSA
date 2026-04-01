class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ans;
        vector<vector<int>> store;
        vector<vector<int>> temp(n);
        vector<int> tp = positions;
        sort(tp.begin(),tp.end());
        map<int,int> mpp;
        for(int i = 0;i<n;i++){
            mpp[tp[i]] = i;
        }
        for(int i = 0;i<n;i++){
            temp[mpp[positions[i]]] = {healths[i],directions[i]-'L',i};
        }
        stack<vector<int>> st;
        for(int i = 0;i<n;i++){
            int val = temp[i][0];
            while(!st.empty() && st.top()[1] < val && temp[i][1] == 0){
                val--;
                st.pop();
            }
            if(!st.empty() && st.top()[1] == val && temp[i][1] == 0) st.pop();
            else if(!st.empty() && st.top()[1] > val && temp[i][1] == 0){
                int t = st.top()[0];
                int v = st.top()[1];
                v = v-1;
                st.pop();
                st.push({t,v});
            }else if(st.empty() && temp[i][1] == 0) {
                store.push_back({temp[i][2],val});
            }else st.push({temp[i][2],temp[i][0]});
        }
        while(!st.empty()){
            store.push_back({st.top()[0],st.top()[1]});
            st.pop();
        }
        sort(store.begin(),store.end());
        for(int i = 0;i<store.size();i++){
            ans.push_back(store[i][1]);
        }
        return ans;
    }
};