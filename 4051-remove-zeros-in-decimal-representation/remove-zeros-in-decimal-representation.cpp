class Solution {
public:
    long long removeZeros(long long n) {
        long long ans = 0;
        long long rev = 0;
        long long val = n;
        while(val != 0){
            long long digit = val % 10;
            val = val / 10;
            if(digit != 0) rev = rev * 10 + digit;
        }
        cout << rev << endl;
        while(rev != 0){
            long long digit = rev % 10;
            rev = rev/10;
            ans = ans * 10 + digit;
        }
        return ans;
    }
};