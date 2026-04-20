class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int startColor = colors[0];
        int temp = 1;
        int n = colors.size();
        while(temp < n && colors[temp] == colors[temp-1]) temp++;
        int startposition = temp;
        int index = temp;
        temp = n-2;
        int endColor = colors[temp];
        while(temp >= 0 && colors[temp] == colors[temp+1]) temp--;
        int endposition = temp;
        int ans = 0;
        for(int i = index;i<n;i++){
            if(colors[i] == startColor) ans = max(ans,abs(i-startposition));
            else ans = max(ans,i);
            if(colors[i] == endColor) ans = max(ans,abs(endposition-i));
            else ans = max(ans,abs(n-i-1));
        }
        return ans;
    }
};