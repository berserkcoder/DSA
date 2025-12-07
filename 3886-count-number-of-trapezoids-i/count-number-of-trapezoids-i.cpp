class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        long long int ans = 0;
        map<int,int> store;
        for(int i = 0;i<points.size();i++){
            store[points[i][1]]++;
        }
        vector<long long int> imp;
        for(auto it : store){
            if(it.second > 1){
                long long int n = it.second-1;
                long long int val = (n*(n+1))/2;
                imp.push_back(val);
            }
        }
        if(imp.size() <= 1) return ans;
        vector<long long int> prefix(imp.size());
        int sum = 0;
        for(int i = imp.size()-1;i>=0;i--){
            sum += imp[i];
            prefix[i] = sum;
        }
        for(int i = 0;i<imp.size()-1;i++){
            ans += (imp[i] * prefix[i+1]) % 1000000007;
        }
        return ans % 1000000007;
    }
};