class Solution {
public:
    bool judgeSquareSum(int c) {
        long long end = sqrt(c);
        long long start = 0;
        while(start <= end){
            long long val = (start*start) + (end*end);
            if(val == c) return true;
            if(val > c) end--;
            if(val < c) start++;
        }
        return false;
    }
};