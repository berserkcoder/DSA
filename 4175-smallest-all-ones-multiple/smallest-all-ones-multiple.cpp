class Solution {
public:
    int minAllOneMultiple(int k) {
        map<int,int> store;
        int rem = 1;
        store[rem]++;
        int ans = 1;
        while(rem != 0){
            rem = (rem * 10 + 1) % k;
            if(store.find(rem) != store.end()) return -1;
            store[rem]++;
            ans++;
        }
        return ans;
    }
};