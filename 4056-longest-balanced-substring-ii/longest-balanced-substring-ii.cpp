class Solution {
public:
    int solo(string& s){
        int count = 1;
        int ans = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i] == s[i-1]) count++;
            else count = 1;
            ans = max(ans,count);
        }
        return ans;
    }

    int duo(string& s,char a,char b){
        map<int,int> hash;
        hash[0] = -1;
        int count = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] != a && s[i] != b){
                hash.clear();
                hash[0] = i;
                count = 0;
                continue;
            }
            if(s[i] == a) count++;
            else if(s[i] == b) count--;
            if(hash.find(count) != hash.end()){
                ans = max(ans,i - hash[count]);
            }else hash[count] = i;
        }
        return ans;
    }

    int trio(string& s){
        map<vector<int>,int> hash;
        hash[{0,0}] = -1;
        int ans = 0;
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a') cnta++;
            else if(s[i] == 'b') cntb++;
            else cntc++;
            vector<int> key = {cntb-cnta,cntc-cnta};
            if(hash.find(key) != hash.end()){
                ans = max(ans,i-hash[key]);
            }else hash[key] = i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        return max({solo(s),duo(s,'a','b'),duo(s,'a','c'),duo(s,'b','c'),trio(s)});
    }
};