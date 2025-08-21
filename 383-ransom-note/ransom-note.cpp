class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mpp;
        for(int i = 0;i<ransomNote.size();i++){
            mpp[ransomNote[i]]++;
        }
        for(int i = 0;i<magazine.size();i++){
            mpp[magazine[i]]--;
        }

        for(auto it : mpp){
            if(it.second > 0) return false;
        }
        return true;
    }
};