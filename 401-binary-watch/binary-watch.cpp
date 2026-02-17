class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        set<string> ans;
        rec(0,0,turnedOn,8,32,ans);
        vector<string> st;
        for(auto it : ans){
            st.push_back(it);
        }
        if(turnedOn >= 9) return st;
        return st;
    }
    void rec(int hours,int minutes,int on,int ch,int cm,set<string>& ans){
        if((ch <= 0 && cm <= 0) || on <= 0){
            if(hours >= 12) return;
            if(minutes >= 60) return;
            if(on < 0) return;
            if(on > 0) return;
            string s = to_string(hours);
            string t = "";
            if(minutes < 10) t += "0";
            t += to_string(minutes);
            string store = s;
            store += ":";
            store += t;
            ans.insert(store);
            return;
        }
        rec(hours,minutes,on,ch/2,cm/2,ans);
        if(ch>0)rec(hours+ch,minutes,on-1,ch/2,cm,ans);
        if(cm>0)rec(hours,minutes+cm,on-1,ch,cm/2,ans);
        // rec(hours+ch,minutes+cm,on-2,ch/2,cm/2,ans);
        
        // rec(hours,minutes,on,ch/2,cm,ans);
        // rec(hours,minutes,on,ch,cm/2,ans);
    }
};