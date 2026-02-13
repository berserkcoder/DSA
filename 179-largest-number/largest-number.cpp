class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        vector<string> n(nums.size());
        for(int i = 0;i<nums.size();i++){
            n[i] = to_string(nums[i]);
        }
        sort(n.begin(),n.end(),[](string &a,string &b) {return a+b > b+a;});

        if(n[0] == "0") return "0";
        for(int i = 0;i<nums.size();i++){
            s += n[i];
        }
        return s;
    }
};