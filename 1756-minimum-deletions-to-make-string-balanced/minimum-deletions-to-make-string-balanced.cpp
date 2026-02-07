class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for (int i = s.size()-1;i>=0;i--){
            if (s[i] == 'a')
                count++;
            else if (count != 0){
                res++;
                count--;
            }
        }
        return res;
    }
};