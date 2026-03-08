class Solution {
public:
    long long minCost(string s, int encCost, int flatCost) {
        vector<int> prefix(s.size());
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1') sum++;
            prefix[i] = sum;
        }
        return check(0,s.size()-1,encCost,flatCost,prefix);
    }
    long long check(long long l,long long r,long long cost1,long long cost2,vector<int>& prefix){
        int x = 0;
        if(l == 0) x = prefix[r];
        else x = prefix[r] - prefix[l-1];
        if((r-l+1) % 2 == 1){
            if(x == 0) return cost2;
            return (r-l+1) * cost1 * x;
        }
        if(x == 0) return cost2;
        return min((r-l+1) * cost1 * x, check(l,(l+r)/2,cost1,cost2,prefix) + check((l+r)/2+1,r,cost1,cost2,prefix));
    }
};