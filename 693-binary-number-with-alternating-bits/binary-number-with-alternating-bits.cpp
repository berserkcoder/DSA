class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = !(n%2);
        while(n!=0){
            if((n & 1) == last) return false;
            last = n & 1;
            n = n >> 1;
        }
        return true;
    }
};