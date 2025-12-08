class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(),0);
        if(k == 0) return ans;
        int flag = true;
        if(k < 0) {flag = false;k=-k;}
        vector<int> prefix(code.size());
        int sum = 0;
        for(int i = 0;i<code.size();i++){
            sum += code[i];
            prefix[i] = sum;
        }
        for(int i = 0;i<code.size();i++){
            // int val = k;
            // while(val != 0){
                if(flag) {
                    // int sum = 0;
                    // for(int j = 1;j<=k;j++){
                        // int index = (i+j) % code.size();
                        // sum += code[index];
                        // val--;
                    // }
                    int index = (i+k) % code.size();
                    int val = 0;
                    if(prefix[index] - prefix[i] >= 0) val = prefix[index] - prefix[i];
                    else {
                        val = prefix[index] - (prefix[i] - prefix[code.size()-1]);
                    }
                    ans[i] = val;
                }else {
                    // int sum = 0;
                    // for(int j = 1;j<=k;j++){
                    //     int index = (i-j);
                    //     if(index < 0) index = index + code.size();
                    //     sum += code[index];
                        // val--;
                    // }
                    int index = i-k;
                    if(index <= 0) index = index + code.size();
                    int index1 = i-1;
                    int val = 0;
                    if(index1 >= 0 && prefix[index1] - prefix[index-1] > 0) val = prefix[index1] - prefix[index-1];
                    else {
                        if(index1 == -1) val =  - (prefix[index-1] - prefix[code.size()-1]);
                        else val = prefix[index1] - (prefix[index-1] - prefix[code.size()-1]);
                    }
                    ans[i] = val;
                }
            // }
        }
        return ans;
    }
};