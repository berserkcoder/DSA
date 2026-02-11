class Solution {
    int mod = 1e9 + 7;

public:
    int countAnagrams(string s) {
        long long ans = 1;
        long long i = 0;
        while (i < s.size()) {
            vector<long long> hash(26, 0);
            while (i < s.size() && s[i] != ' ') {
                hash[s[i] - 'a']++;
                i++;
            }
            long long val = 0;
            long long temp = 1;
            for (int j = 0; j < 26; j++)
                val += hash[j];
            for (int j = 1; j <= val; j++)
                temp = (temp * j) % mod;
            for (int j = 0; j < 26; j++)
                temp = (temp * modInverse(fact(hash[j]))) % mod;
            ans = (ans * temp) % mod;
            i++;
        }
        return ans;
    }
    long long fact(int n) {
        long long val = 1;
        for (int i = 1; i <= n; i++)
            val = (val * i) % mod;
        return val;
    }
    long long power(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return result;
    }

    long long modInverse(long long a) { return power(a, mod - 2); }
};