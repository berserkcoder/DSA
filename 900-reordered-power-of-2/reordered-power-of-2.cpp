class Solution {
public:
    bool reorderedPowerOf2(int n) {
        map<vector<int>,int> mpp;
        long x = 1;
        while(x <= 1e9){
            vector<int> store(10,0);
            int p = x;
            while(p!=0){
                int digit = p % 10;
                store[digit]++;
                p = p/10;
            }
            mpp[store]++;
            x = 2*x;
        }
        vector<int> numstore(10,0);
        int p = n;
        while(p!=0){
            int digit = p % 10;
            numstore[digit]++;
            p = p/10;
        }
        if(mpp.find(numstore) == mpp.end()) return false;
        return true;
    }
};