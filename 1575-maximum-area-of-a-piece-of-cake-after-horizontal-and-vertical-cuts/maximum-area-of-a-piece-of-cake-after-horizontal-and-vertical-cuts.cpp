class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int hmax = horizontalCuts[0];
        int vmax = verticalCuts[0];
        for(int i = 0;i<horizontalCuts.size()-1;i++){
            if(hmax < (horizontalCuts[i+1] - horizontalCuts[i])) hmax = (horizontalCuts[i+1] - horizontalCuts[i]);
        }
        for(int i = 0;i<verticalCuts.size()-1;i++){
            if(vmax < (verticalCuts[i+1] - verticalCuts[i])) vmax = (verticalCuts[i+1] - verticalCuts[i]);
        }
        if(hmax < h-horizontalCuts[horizontalCuts.size()-1]) hmax = h-(horizontalCuts[horizontalCuts.size()-1]);
        if(vmax < w-verticalCuts[verticalCuts.size()-1]) vmax = w-(verticalCuts[verticalCuts.size()-1]);
        long long int ans = ((long long int)((hmax%1000000007))*((long long int)(vmax%1000000007))) % 1000000007;
        return ans % 1000000007;
    }
};