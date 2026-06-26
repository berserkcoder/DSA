class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string col = "";
        vector<string> ans;
        for(int i = 0;i<m;i++){
            string path = "";
            if(i == 0){
                for(int j = 0;j<n;j++){
                    path += ".";
                }
            }else{
                for(int j = 0;j<n-1;j++){
                    path += "#";
                }
                path += ".";
            }
            ans.push_back(path);
        }
        return ans;
    }
};