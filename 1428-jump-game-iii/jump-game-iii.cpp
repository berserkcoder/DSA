class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            if(arr[ind] == 0) return true;
            if(arr[ind]+ind < arr.size() && vis[arr[ind]+ind] == 0){
                q.push(arr[ind]+ind);
                vis[arr[ind]+ind] = 1;
            }
            if(-arr[ind]+ind >= 0 && vis[-arr[ind]+ind] == 0){
                q.push(-arr[ind]+ind);
                vis[-arr[ind]+ind] = 1;
            }
        }
        return false;
    }
};