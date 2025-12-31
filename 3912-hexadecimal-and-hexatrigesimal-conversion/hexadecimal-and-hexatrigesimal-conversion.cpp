class Solution {
public:
    string concatHex36(int n) {
        int val = n*n;
        string ans = "";
        string store = "";
        while(val!=0){
            int modulo = val % 16;
            if(modulo >= 0 && modulo<=9) store += to_string(modulo);
            else store += (modulo+55);
            val = val / 16;
        }
        store = reverse(store);
        ans += store;
        val = n*n*n;
        store = "";
        while(val!=0){
            int modulo = val % 36;
            if(modulo >= 0 && modulo<=9) store += to_string(modulo);
            else store += (modulo+55);
            val = val / 36;
        }
        store = reverse(store);
        ans += store;
        return ans;
    }
    string reverse(string s){
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};