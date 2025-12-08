class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        if(k == 0) return ans;
        int flag = true;
        if(k < 0) {flag = false;k=-k;}
        for(int i = 0;i<code.size();i++){
            int val = k;
            while(val != 0){
                if(flag) {
                    int sum = 0;
                    for(int j = 1;j<=k;j++){
                        int index = (i+j) % code.size();
                        sum += code[index];
                        val--;
                    }
                    ans[i] = sum;
                }else {
                    int sum = 0;
                    for(int j = 1;j<=k;j++){
                        int index = (i-j);
                        if(index < 0) index = index + code.size();
                        cout << code[index] << " ";
                        sum += code[index];
                        val--;
                    }
                    cout << endl ;
                    ans[i] = sum;
                }
            }
        }
        return ans;
    }
};