class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        long long ans = 0;
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<technique1.size();i++){
            pq.push({technique1[i]-technique2[i],i});
        }
        int val = 0;
        int index = -1;
        while(k != 0){
            val = pq.top().first;
            index = pq.top().second;
            pq.pop();
            ans += technique1[index];
            k--;
        }
        while(!pq.empty()){
            val = pq.top().first;
            index = pq.top().second;
            pq.pop();
            if(val >= 0){
                ans += technique1[index];
            }else ans += technique2[index];
        }
        return ans;
    }
};