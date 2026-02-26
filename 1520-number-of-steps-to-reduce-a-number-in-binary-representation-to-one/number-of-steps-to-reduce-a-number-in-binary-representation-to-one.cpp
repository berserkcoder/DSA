class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        bool flag = true;
        for(int i = s.size()-1;i>=0;i--){
            if(i != 0 && s[i] == '1' && flag == true){
                ans += 2;
                flag = false;
            }
            else if(s[i] == '1' && flag == false){
                ans++;
            }
            else if(s[i] == '0'){
                if(flag) ans++;
                else {
                    ans += 2;
                    // flag = true;
                }
            }
        }
        return ans;
    }
};