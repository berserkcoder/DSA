class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long count = 1;
        for(int i = 0;i<prices.size()-1;i++){
            if(prices[i] != prices[i+1]+1){
                ans = ans + (count * (count+1))/2;
                count = 1;
            }else {
                count++;
            }
            cout << endl;
        }
        ans = ans + (count * (count+1))/2;
        return ans;
    }
};