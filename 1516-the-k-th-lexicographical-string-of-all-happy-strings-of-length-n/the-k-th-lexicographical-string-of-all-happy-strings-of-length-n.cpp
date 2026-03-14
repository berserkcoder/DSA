class Solution {
    vector<string> ans;
public:
    string getHappyString(int n, int k) {
        string s = "";
        rec(n,s,' ');
        if(k > ans.size()) return "";
        return ans[k-1];
    }
    void rec(int n,string s,char previous){
        if(n == 0) {
            ans.push_back(s);
            return;
        }
        if(previous != 'a') rec(n-1,s + 'a','a');
        if(previous != 'b') rec(n-1,s + 'b','b');
        if(previous != 'c') rec(n-1,s + 'c','c');
    }
};