class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size();i++){
            int  start = 0;
            int end = matrix[i].size()-1;
            while(start < end){
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
        for(int i = 0;i< matrix.size()-1;i++){
            for(int j = 0;j<matrix[i].size()-1-i;j++){
                int temp = matrix[matrix.size()-1-j][matrix[i].size()-1-i];
                matrix[matrix.size()-1-j][matrix[i].size()-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};