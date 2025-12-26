class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> yes(customers.size(),0);
        vector<int> no(customers.size(),0);
        if(customers[customers.size()-1] == 'Y') yes[customers.size()-1] = 1;
        if(customers[0] == 'N') no[0] = 1;
        for(int i = customers.size()-2;i>=0;i--){
            if(customers[i] == 'Y') yes[i] = yes[i+1] + 1;
            else yes[i] = yes[i+1];
        }
        for(int i = 1;i<customers.size();i++){
            if(customers[i] == 'N') no[i] = no[i-1] + 1;
            else no[i] = no[i-1];
        }
        int minPenalty = yes[0];
        int ans = 0;
        cout << minPenalty << " ";
        for(int i = 0;i<customers.size()-1;i++){
            if(no[i] + yes[i+1] < minPenalty) {
                minPenalty = no[i] + yes[i+1];
                ans = i+1;
            }
            cout << minPenalty << " ";
        }
        if(no[customers.size()-1] < minPenalty) ans = customers.size();
        return ans;
    }
};