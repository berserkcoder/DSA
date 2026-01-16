class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> hash(26,0);
        for(int i = 0;i<s1.size();i++){
            hash[s1[i]-'a']++;
        }
        int l = 0,r = 0;
        int count = 0;
        while(r < s2.size()){
            hash[s2[r]-'a']--;
            while(hash[s2[r]-'a'] < 0){
                hash[s2[l]-'a']++;
                l++;
            }
            if(r-l+1 == s1.size()) return true;
            r++;
        }
        return false;
    }
};