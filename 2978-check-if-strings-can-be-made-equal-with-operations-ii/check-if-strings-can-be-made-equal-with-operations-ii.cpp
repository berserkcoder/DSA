class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int> mpp1;
        map<char,int> mpp2;
        for(int i = 0;i<s1.size();i++){
            if(i % 2 == 0){
                mpp1[s1[i]]++;
                if(mpp1[s1[i]] == 0) mpp1.erase(s1[i]);
                mpp1[s2[i]]--;
                if(mpp1[s2[i]] == 0) mpp1.erase(s2[i]);
            }else {
                mpp2[s1[i]]++;
                if(mpp2[s1[i]] == 0) mpp2.erase(s1[i]);
                mpp2[s2[i]]--;
                if(mpp2[s2[i]] == 0) mpp2.erase(s2[i]);
            }
        }
        if(mpp1.empty() && mpp2.empty()) return true;
        return false;
    }
};