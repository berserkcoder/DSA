class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ans = "";
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = 0;
            if(i>=0 && a[i] == '1') sum += 1;
            if(j>=0 && b[j] == '1') sum += 1;
            if(sum + carry == 0) {
                ans = ans + '0';
                carry = 0;
            }
            else if(sum + carry == 2) {
                ans = ans + '0';
                carry = 1;
            }else if(sum + carry == 3){
                ans = ans + '1';
                carry = 1;
            }else{
                ans = ans + '1';
                carry = 0;
            }
            i--;
            j--;
        }
        if(carry != 0) ans = ans + '1';
        int s = 0;
        int e = ans.size() - 1;
        while(s<=e){
            char temp = ans[s];
            ans[s] = ans[e];
            ans[e] = temp;
            s++;
            e--;
        }
        return ans;
    }
};