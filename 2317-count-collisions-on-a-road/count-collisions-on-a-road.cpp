class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0;
        int count = 0;
        int flag = 0;
        for(int i = 0;i<directions.size();i++){
            if(directions[i] == 'R') count++;
            if(directions[i] == 'L') {
                if(flag == 1 && count == 0) {
                    ans++;
                }
                if(count > 0) {
                    ans += count+1;
                    count = 0;
                    flag = 1;
                }
            }
            if(directions[i] == 'S') {
                if(count > 0) {
                    ans += count;
                    count = 0;
                }
                flag = 1;
            }
        }
        return ans;
    }
};