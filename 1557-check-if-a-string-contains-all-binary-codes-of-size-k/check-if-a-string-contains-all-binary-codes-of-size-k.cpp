class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>=19) return false;
        map<string,int> store;
        int l = 0;
        while(l+k-1 < s.size()){
            string t = s.substr(l,k);
            if(store.find(t) == store.end()) store[t]++;
            l++;
        }
        return store.size() == pow(2,k);
    }
};