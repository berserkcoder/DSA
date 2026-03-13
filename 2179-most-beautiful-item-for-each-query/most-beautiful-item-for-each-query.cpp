class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = queries.size();
        vector<vector<int>> q;
        for(int i = 0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        vector<int> ans(n);
        set<int> store;
        int previous = 0;
        for(int i = 0;i<n;i++){
            int value = q[i][0];
            int index = q[i][1];
            int start = 0;
            int end = items.size()-1;
            while(start <= end){
                int mid = (start+end)/2;
                if(items[mid][0] > value) end = mid-1;
                else start = mid+1;
            }
            for(int j = previous;j<start;j++){
                store.insert(items[j][1]);
            }
            previous = start;
            auto it = store.end();
            if(it != store.begin()){
                it--;
                ans[index] = *it;
            }else ans[index] = 0;
        }
        return ans;
    }
};