class Solution {
public:
    int maximum69Number (int num) {
        int rev = 0;
        while(num!=0){
            int digit = num%10;
            rev = rev * 10 + digit;
            num = num/10;
        }
        int limit = 1;
        num = 0;
        while(rev != 0){
            int digit = rev % 10;
            if(digit == 6 && limit > 0){
                digit = 9;
                limit--;
            }
            num = num * 10 + digit;
            rev = rev/10;
        }
        return num;
    }
};