class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int missing = 1;
        while(i < arr.size() && k!=0){
            if(arr[i] != missing){
                k--;
                missing++;
            }else{
                i++;
                missing++;
            }
        }
        missing += k;
        return missing-1;
    }
};