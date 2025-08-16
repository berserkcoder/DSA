class Solution {
public:
    string removeDigit(string number, char digit) {
        int index = -1;
        bool flag = true;
        string ans = "";
        for(int i = 0;i<number.size()-1;i++){
            if(number[i] == digit){
                if(number[i+1] > digit){
                    index = i;
                    flag = false;
                    break;
                }else index = i;
            }
        }
        if(flag && number[number.size()-1] == digit) index = number.size()-1;
        for(int i = 0;i<index;i++){
            ans += number[i];
        }
        for(int i = index+1;i<number.size();i++){
            ans += number[i];
        }
        return ans;
    }
};