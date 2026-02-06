class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        map<string,int> subdomains;
        for(int i = 0;i<cpdomains.size();i++){
            int val = 0;
            for(int j = 0;j<cpdomains[i].size();j++){
                if(cpdomains[i][j] == ' ') break;
                int digit = cpdomains[i][j] - 48;
                val = (val*10) + digit; 
            }
            stack<char> st;
            for(int j = cpdomains[i].size()-1;j>=0;j--){
                if(cpdomains[i][j] == '.' || cpdomains[i][j] == ' '){
                    vector<char> store;
                    string domain = "";
                    while(!st.empty()){
                        domain += st.top();
                        store.push_back(st.top());
                        st.pop();
                    }
                    subdomains[domain] += val;
                    for(int k = store.size()-1;k>=0;k--){
                        st.push(store[k]);
                    }
                    st.push('.');
                    if(cpdomains[i][j] == ' ')break;
                }else st.push(cpdomains[i][j]);
            }
        }
        for(auto it : subdomains){
            string preanswer = "";
            preanswer += to_string(it.second);
            preanswer += " ";
            preanswer += it.first;
            ans.push_back(preanswer);
        }
        return ans;
    }
};