class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int first = complexity[0];
        long long ans = 1;
        for(long long i = 1;i<complexity.size();i++){
            if(first >= complexity[i]) return 0;
            ans = (ans * i) % 1000000007;
        }
        return ans;
    }
};