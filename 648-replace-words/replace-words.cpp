class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        unordered_map<string,int> mpp;
        for(int i = 0;i<dictionary.size();i++){
            mpp[dictionary[i]]++;
        }
        int i = 0;
        string temp = "";
        while(i < sentence.size()){
            if(mpp.find(temp) != mpp.end()){
                while(i < sentence.size() && sentence[i] != ' ') i++;
            }
            if(i < sentence.size() && sentence[i] == ' ') {
                ans += temp;
                temp = "";
                ans += " ";
                // continue;
            }
            if(i < sentence.size() && sentence[i] != ' ') temp += sentence[i];
            i++;
        }
        ans += temp;
        return ans;
    }
};