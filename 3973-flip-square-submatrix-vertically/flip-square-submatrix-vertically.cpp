class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y;i<y+k;i++){
            int start = x;
            int end = x+k-1;
            while(start < end){
                int temp = grid[start][i];
                grid[start][i] = grid[end][i];
                grid[end][i] = temp;
                start++;
                end--;
            }
        }
        return grid;
    }
};