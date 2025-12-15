class Solution {
public:
    string reverseWords(string s) {
        string store = "";
        string ans = "";
        int firstVowelCount = 0;
        int vowelCount = 0;
        int index = -1;
        for(int i = 0;i<s.size();i++){
            if(s[i] == ' ') {
                index = i+1;
                break;
            }else {
                if(vowelCheck(s[i])) firstVowelCount++;
            }
            store += s[i];
        }
        ans += store;
        if(index == -1) return ans;
        store = "";
        ans += " ";
        for(int i = index;i<s.size();i++){
            if(s[i] == ' '){
                if(vowelCount == firstVowelCount){
                    ans += rev(store);
                    ans += " ";
                }else {
                    ans += store;
                    ans += " ";
                }
                vowelCount = 0;
                store = "";
            }else {
                if(vowelCheck(s[i])) vowelCount++;
                store += s[i];
            }
        }
        if(vowelCount == firstVowelCount) ans += rev(store);
        else ans += store;
        return ans;
    }
    bool vowelCheck(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o'  || s == 'u')return true;
        return false;
    }
    string rev(string s){
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        return s;
    }
};