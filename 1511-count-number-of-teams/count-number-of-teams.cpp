class Solution {
public:
    int numTeams(vector<int>& rating) {
        set<int> right,left;
        int ans = 0;
        for(int i = 0;i<rating.size();i++){
            right.insert(rating[i]);
        }
        for(int i = 0;i<rating.size();i++){
            left.insert(rating[i]);
            int indexleft = getSetIndex(left, rating[i]);
            int indexright = getSetIndex(right, rating[i]);
            ans += indexleft * (right.size()-indexright-1);
            ans += indexright * (left.size()-indexleft-1);
            right.erase(rating[i]);
        }
        return ans;
    }
    int getSetIndex(const std::set<int>& s, int value) {
        int index = 0;
        for (int element : s) {
            if (element == value) {
                return index;
            }
            index++;
        }
        return -1; // Element not found
    }
};