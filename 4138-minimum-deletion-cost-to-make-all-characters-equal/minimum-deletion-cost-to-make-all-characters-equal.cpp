class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long> hash(26,0);
        for(int i = 0;i<s.size();i++){
            hash[s[i] - 'a'] += cost[i]; 
        }
        long long max = hash[0];
        long long sum = hash[0];
        for(int i = 1;i<26;i++){
            sum += hash[i];
            if(hash[i] > max) max = hash[i];
        }
        return sum - max;
    }
};