class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1;i<=num2;i++){
            vector<int> store;
            int val = i;
            while(val!=0){
                int digit = val % 10;
                store.push_back(digit);
                val = val/10;
            }
            if(store.size() > 2){
                for(int j = 1;j<store.size()-1;j++){
                    if(store[j] > store[j-1] && store[j] > store[j+1]) ans++;
                    if(store[j] < store[j-1] && store[j] < store[j+1]) ans++;
                }
            } 
        }
        return ans;
    }
};