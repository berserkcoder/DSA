class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        for(int i = 0;i<points.size();i++){
            int temp = points[i][0];
            points[i][0] = points[i][1];
            points[i][1] = temp;
        }
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] < b[1]; // for equal x, sort y descending
                 }
                 return a[0] > b[0]; // otherwise sort x ascending
             });
        int ans = 0;
        pair<int,int> range;
        for(int i = 0;i<points.size();i++){
            int position = points[i][1];
            range = {position-1,1e9};
            for(int j = i+1;j<points.size();j++){
                if(points[j][1] > range.first && points[j][1] < range.second){
                    ans++;
                    if(position < points[j][1]) range.second = points[j][1];
                    if(position == points[j][1]) range.second = points[j][1];
                }
            }
        }
        return ans;
    }
};