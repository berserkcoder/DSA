class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans = 0;
        if(numWanted == 0 || useLimit == 0) return ans;
        vector<vector<int>> merged(values.size(),vector<int>(2));
        for(int i = 0;i<values.size();i++){
            merged[i][0] = values[i];
            merged[i][1] = labels[i];
        }
        sort(merged.begin(),merged.end());
        map<int,int> mpp;
        for(int i = values.size()-1;i>=0;i--){
            // cout << merged[i][0] << "  " << merged[i][1] << endl;
            if(mpp.find(merged[i][1]) == mpp.end()){
                mpp[merged[i][1]]++;
                ans += merged[i][0];
                numWanted--;
            }else if(mpp[merged[i][1]] < useLimit){
                mpp[merged[i][1]]++;
                ans += merged[i][0];
                numWanted--;
            }
            if(numWanted <= 0) break;
        }
        return ans;
    }
};