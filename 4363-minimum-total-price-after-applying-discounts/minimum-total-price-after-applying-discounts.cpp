class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.begin(),discounts.end());
        sort(prices.begin(),prices.end());
        int i = prices.size()-1;
        int j = discounts.size()-1;
        double ans = 0;
        while(i >= 0){
            if(j >= 0){
                ans += (double)(prices[i]) * (double)(100 - discounts[j])/100;
                j--;
            }else ans += (double)(prices[i]);
            i--;
        }
        return ans;
    }
};