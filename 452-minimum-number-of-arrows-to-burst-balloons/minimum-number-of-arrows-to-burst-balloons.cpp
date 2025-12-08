class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = points.size();
        sort(points.begin(), points.end(), [](const std::vector<int>& a, 
            const std::vector<int>& b) {
            return a[1] < b[1]; 
        });
        int end = points[0][1];
        for(int i = 0;i<points.size()-1;i++){
            cout << points[i][0] << " " << points[i][1] << endl;
            if(end >= points[i+1][0]) ans--;
            else end = points[i+1][1];
        }
        return ans;
    }
    
};