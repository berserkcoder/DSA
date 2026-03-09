class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        for(int i = 0;i<capacity.size();i++){
            if(ans == -1 && capacity[i] >= itemSize) ans = i;
            else if(ans != -1 && capacity[ans] > capacity[i] && capacity[i] >= itemSize) ans = i;
        }
        return ans;
    }
};