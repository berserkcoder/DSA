class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> ans(n,1);
        
    
        while(k--){
            for(int j = 1; j<n; j++){
                ans[j] =(ans[j-1] + ans[j]) % 1000000007;
            }
        }
       
        return ans[n-1] ;
    }
};