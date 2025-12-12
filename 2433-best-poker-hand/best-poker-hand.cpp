class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int s = suits[0];
        int flag = true;
        for(int i = 0;i<suits.size();i++){
            if(suits[i] != s) flag = false;
        }
        if(flag) return "Flush";
        int count = 0;
        vector<int> hash(14,0);
        for(int i = 0;i<ranks.size();i++){
            hash[ranks[i]]++;
        }
        for(int i = 0;i<hash.size();i++){
            if(hash[i] > count) count = hash[i];
        }
        if(count <= 1) return "High Card";
        if(count == 2) return "Pair";
        return "Three of a Kind";
    }
};