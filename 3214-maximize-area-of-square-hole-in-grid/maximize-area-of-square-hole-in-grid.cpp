class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int ans = 1;
        int count1 = 1;
        int maxh = 1;
        int count2 = 1;
        int maxv = 1;
        for(int i = 1;i<hBars.size();i++){
            if(hBars[i] != hBars[i-1]+1){
                if(count1 > maxh) maxh = count1;
                count1 = 1;
            }else count1++;
        }
        if(count1 > maxh) maxh = count1;
        for(int i = 1;i<vBars.size();i++){
            if(vBars[i] != vBars[i-1]+1){
                if(count2 > maxv) maxv = count2;
                count2 = 1;
            }
            else count2++;
        }
        if(count2 > maxv) maxv = count2;
        ans += min(maxh,maxv);
        return ans * ans;
    }
};