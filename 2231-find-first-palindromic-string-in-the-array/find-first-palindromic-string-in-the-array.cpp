class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string s = "";
        for(int i = 0;i<words.size();i++){
            s = "";
            for(int j = 0;j<words[i].size();j++){
                s += words[i][j];
            }
            if(isPalindrome(s)) return s;
        }
        return "";
    }
    bool isPalindrome(string words){
        int s = 0;
        int e = words.size()-1;
        while(s < e){
            if(words[s] != words[e]) return false;
            s++;
            e--;
        }
        return true;
    }
};