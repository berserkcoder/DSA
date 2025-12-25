class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long sum = 0;
        for(int i = 0;i<k;i++){
            int last = happiness.size() - 1 - i;
            if(happiness[last] - i <= 0){
                break;
            }
            sum = sum + happiness[last]-i;
        }
        return sum;
    }
};