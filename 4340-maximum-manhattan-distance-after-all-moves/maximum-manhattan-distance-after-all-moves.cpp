class Solution {
public:
    int maxDistance(string moves) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int u = 0;
        int d = 0;
        int n = 0;
        for(int i = 0;i<moves.size();i++){
            if(moves[i] == 'L') l++;
            if(moves[i] == 'R') r++;
            if(moves[i] == 'U') u++;
            if(moves[i] == 'D') d++;
            if(moves[i] == '_') n++;
        }
        ans += abs(u-d);
        ans += abs(l-r);
        ans += n;
        return ans;
    }
};