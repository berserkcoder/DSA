class Solution {
public:
    int minimumFlips(int n) {
        vector<int> store;
        int val = n;
        while(val != 0){
            int digit = val % 2;
            store.push_back(digit);
            val = val/2;
        }
        int ans = 0;
        for(int i = 0;i<store.size()/2;i++){
            if(store[i] != store[store.size()-i-1]) ans += 2;
        }
        return ans;
    }
};