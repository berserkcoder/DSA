class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        bool flag = true;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1' && flag == false) ans++;
            else if(s[i] == '0' && flag == true) ans++;
            flag = !flag;
        }
        int temp = 0;
        flag = false;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1' && flag == false) temp++;
            else if(s[i] == '0' && flag == true) temp++;
            flag = !flag;
        }
        ans = min(temp,ans);
        return ans;
    }
};