class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<int> hash(33,0);
        for(int i = 2;i<32;i++){
            bool flag = true;
            for(int j = 2;j<i;j++){
                if(i % j == 0) flag = false;
            }
            if(flag) hash[i] = 1;
        }
        for(int i = left;i<=right;i++){
            int count = 0;
            int val = i;
            while(val != 0){
                if(val % 2 == 1) count++;
                val = val/2;
            }
            if(hash[count] == 1) ans++;
        }
        return ans;
    }
};