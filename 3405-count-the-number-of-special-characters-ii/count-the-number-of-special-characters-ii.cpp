class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> store(26,0);
        for(int i = 0;i<word.size();i++){
            if(word[i] >= 65 && word[i] <= 91){
                if(store[word[i]-'A'] == 0) store[word[i]-'A'] = 3;
                if(store[word[i]-'A'] == 1) store[word[i]-'A'] = 2;
            }else {
                if(store[word[i]-'a'] == 0) store[word[i]-'a'] = 1;
                if(store[word[i]-'a'] == 2) store[word[i]-'a'] = 3;
            }
        }
        int count = 0;
        for(int i = 0;i<26;i++){
            if(store[i] == 2) count++;
        }
        return count;
    }
};