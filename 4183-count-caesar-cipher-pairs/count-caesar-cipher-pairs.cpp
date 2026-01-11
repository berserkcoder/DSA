class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> mpp;
        long long ans = 0;
        mpp[words[0]]++;
        for(int i = 1;i<words.size();i++){
            bool flag = true;
            string original = words[i];
            string newWord = "";
            string currentWord = original;
            for(int ch = 0;ch<=26;ch++){
                for(int j = 0;j<words[0].size();j++){
                    if(currentWord[j] != 'z')newWord += char(currentWord[j] + 1);
                    else newWord += char(currentWord[j] - 25);
                }
                currentWord = newWord;
                if(mpp.find(newWord) != mpp.end()){
                    ans += mpp[newWord];
                    mpp[newWord]++;
                    flag = false;
                    break;
                }else newWord = "";
                
            }
            if(flag) mpp[original]++;
        }
        return ans;
    }
};