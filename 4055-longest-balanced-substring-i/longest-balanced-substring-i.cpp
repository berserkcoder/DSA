class Solution {
public:
    int longestBalanced(string s) {
        int ans = 1;
        int n = s.size();
        for(int i = 0;i<n;i++){
            vector<int> hash(26,0);
            for(int j = i;j<n;j++){
                hash[s[j]-'a']++;
                int temp = 0;
                int val = 0;
                for(int k = 0;k<26;k++){
                    if(hash[k] == 0)continue;
                    if(val == 0) val = hash[k];
                    if(hash[k] != val){
                        temp = 0;
                        break;
                    }
                    if(hash[k] == val) temp += val;
                }
                ans = max(temp,ans);
            }

        }
        return ans;
    }
};