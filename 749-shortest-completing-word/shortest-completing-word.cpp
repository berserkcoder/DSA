class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans = "";
        vector<int> hash(26,0);
        for(int i = 0;i<licensePlate.size();i++){
            if(licensePlate[i] >= 97 && licensePlate[i] <= 122){
                hash[licensePlate[i]-'a']++;
            }else if(licensePlate[i] >= 65 && licensePlate[i] <= 91){
                hash[licensePlate[i]-'a'+32]++;
            }
        }
        for(int i = 0;i<words.size();i++){
            vector<int> store(26,0);
            bool flag = true;
            for(int j = 0;j<words[i].size();j++){
                store[words[i][j] - 'a']++;
            }
            for(int j = 0;j<26;j++){
                if(store[j] < hash[j]) {
                    flag = false;
                    break;
                }
                
            }
            if(flag){
                if(ans == "" || ans.size() > words[i].size()) ans = words[i];
            }
        }
        return ans;
    }
};