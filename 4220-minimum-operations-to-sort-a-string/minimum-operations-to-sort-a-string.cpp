class Solution {
public:
    int minOperations(string s) {
        if(s.size() == 1) return 0;
        if(s.size() == 2){
            if(s[0] <= s[1]) return 0;
            return -1;
        }
        bool flag = true;
        char smallest = 'z';
        char largest = 'a';
        for(int i = 1;i<s.size()-1;i++){
            if(s[i] < s[i-1]) flag = false;
            if(s[i] > largest) largest = s[i];
            if(s[i] < smallest) smallest = s[i];
        }
        
        if(s[0] > largest && s[s.size()-1] < smallest) return 3;
        if(s[0] > largest) largest = s[0];
        if(s[s.size()-1] < smallest) smallest = s[s.size()-1];
        if(flag && s[s.size()-1] >= largest) return 0;
        if(s[0] <= smallest || s[s.size()-1] >= largest) return 1; 
        return 2;
    }
};