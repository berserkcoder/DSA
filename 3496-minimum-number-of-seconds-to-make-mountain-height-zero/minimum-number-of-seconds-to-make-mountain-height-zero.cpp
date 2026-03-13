class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long ans = 0;
        int n = workerTimes.size();
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        for(int i = 0;i<n;i++){
            pq.push({workerTimes[i],workerTimes[i],1});
        } 
        int store = mountainHeight;
        while(mountainHeight > 0){
            long long val = pq.top()[1];
            long long days = pq.top()[2];
            long long current = pq.top()[0];
            pq.pop();
            // cout << val << " " << days << endl;
            long long temp = val * (days+1);
            pq.push({current+temp,val,days+1});
            mountainHeight--;
        }
        while(store > 0){
            long long val = pq.top()[1];
            long long days = pq.top()[2];
            long long current = pq.top()[0];
            pq.pop();
            if(days != 1)ans = max(ans,current-(val*days));
            store -= days-1;
        }
        return ans;
    }
};