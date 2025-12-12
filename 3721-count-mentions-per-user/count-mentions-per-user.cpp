class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers,0);
        vector<int> online(numberOfUsers,0);
        sort(events.begin(), events.end(), 
              [](const vector<string>& a, const vector<string>& b) {
                int t1 = stoi(a[1]);
                int t2 = stoi(b[1]);

                if (t1 != t2) return t1 < t2;

                // Same timestamp: OFFLINE must come before MESSAGE
                if (a[0] == b[0]) return false;
                return a[0] == "OFFLINE";
            });
        for(int i = 0;i<events.size();i++){
            if(events[i][0][0] == 'M'){
                if(events[i][2][0] == 'A'){
                    for(int j = 0;j<numberOfUsers;j++){
                        ans[j]++;
                    }
                }else if(events[i][2][0] == 'H'){
                    int compare = stoi(events[i][1]);
                    for(int h = 0;h<online.size();h++){
                        if(online[h] <= compare) ans[h]++;
                    }
                }else {
                    int space = 2;
                    int ind = 0;
                    while(space<events[i][2].size()){
                        if(events[i][2][space] == ' ') {
                            space += 3;
                            ans[ind]++;
                            ind = 0;
                            continue;
                        }
                        ind = ind * 10 + (events[i][2][space] - 48);
                        space++;
                    }
                    ans[ind]++;
                }
            }else {
                int val = stoi(events[i][1]);
                int index = stoi(events[i][2]);
                online[index] = val+60;
            }
        }
        return ans;
    }
};