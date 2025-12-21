class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lowi = 0;
        int highi = m-1;
        int lowj = 0;
        int highj = n-1;

        while(lowi<=highi&&lowj<=highj){
            int midi = lowi + (highi-lowi)/2;
            int midj = lowj + (highj-lowj)/2;

            if(matrix[midi][midj]==target){
                return true;
            }
            else if(matrix[midi][midj]>target&&target<matrix[midi][0]){
                highi = midi - 1;
            }
            else if(matrix[midi][midj]>target&&target>=matrix[midi][0]){
                highj = midj - 1;
            }
            else if(matrix[midi][midj]<target&&target>matrix[midi][n-1]){
                lowi = midi + 1;
            }
            else if(matrix[midi][midj]<target&&target<=matrix[midi][n-1]){
                lowj = midj + 1;
            }
            else return false;
        }
        
        return false;
    }
};