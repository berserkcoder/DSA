class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int pos = 0;
        while(n!=0){
            int digit = n%2;
            n = n/2;
            pos++;
            if(digit == 1){
                break;
            }
        }
        int pre = pos;
        while(n != 0){
            int digit = n % 2;
            n = n/2;
            pos++;
            if(digit == 1){
                ans = max(ans,pos-pre);
                pre = pos;
            }
        }
        return ans;
    }
};