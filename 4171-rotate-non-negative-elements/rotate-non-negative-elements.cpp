class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positive;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= 0) positive.push_back(nums[i]);
        }
        if(positive.size() == 0) return nums;
        int n = positive.size();
        k = k % n;
        reverse(positive,0,k-1);
        reverse(positive,k,n-1);
        reverse(positive,0,n-1);
        int j = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] >= 0){
                nums[i] = positive[j];
                j++;
            }
        }
        return nums;
    }
    void reverse(vector<int>& arr,int start,int end){
        while(start < end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
};