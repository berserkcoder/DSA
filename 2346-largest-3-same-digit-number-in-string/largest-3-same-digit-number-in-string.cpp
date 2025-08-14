class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int count = 1;
        for(int i = 1;i<num.size();i++){
            if(num[i-1] == num[i]){
                count++;
                if(count == 3){
                    if(ans == "") ans = string(1, num[i]) + num[i] + num[i];
                    else if(ans[0] < num[i]) ans = string(1, num[i]) + num[i] + num[i];
                }
            }else count = 1;
        }
        return ans;
    }
};