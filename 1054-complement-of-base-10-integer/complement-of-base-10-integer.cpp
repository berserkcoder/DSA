class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        string s = "";
        while(n != 0){
            int digit = n % 2;
            s += to_string(!digit);
            n = n/2;
        }
        int ans = 0;
        int val = 1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1') ans += val;
            val = val*2;
        }
        return ans;
    }
};