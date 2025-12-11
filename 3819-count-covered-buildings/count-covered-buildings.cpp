class Solution {
public:
    int countCoveredBuildings(int k, vector<vector<int>>& buildings) {
        int m = 0;
        int n = 0;
        for(int i = 0;i<buildings.size();i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            m = max(m,x);
            n = max(n,y);
        }
        vector<int> xmin(n+1,INT_MAX);
        vector<int> xmax(n+1,0);
        vector<int> ymin(m+1,INT_MAX);
        vector<int> ymax(m+1,0);
        for(int i = 0;i<buildings.size();i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            xmin[y] = min(xmin[y],x);
            xmax[y] = max(xmax[y],x);
            ymin[x] = min(ymin[x],y);
            ymax[x] = max(ymax[x],y);
        }
        int ans = 0;
        for(int i = 0;i<buildings.size();i++){
            int x = buildings[i][0];
            int y = buildings[i][1];
            bool xaxis = (xmin[y] < x) && (x < xmax[y]);
            bool yaxis = (ymin[x] < y) && (y < ymax[x]);
            if(xaxis && yaxis) ans++;
        }
        return ans;
    }
};