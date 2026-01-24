class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> stringDifference(s.size());
        for(int i = 0;i<s.size();i++){
            stringDifference[i] = abs(s[i]-t[i]);
        }
        int ans = 0;
        int r = 0;
        int l = 0;
        int sum = 0;
        while(r < s.size()){
            sum += stringDifference[r];
            while(sum > maxCost){
                if(ans < r-l) ans = r-l;
                sum -= stringDifference[l];
                l++;
            }
            r++;
        }
        if(ans < r-l) ans = r-l;
        return ans;
    }
};