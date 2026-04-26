class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        int maxi = 0;
        for(int i = 0;i<n;i++){
            left[i] = maxi;
            maxi = max(nums[i],maxi);
        }
        maxi = 0;
        for(int i = n-1;i>=0;i--){
            right[i] = maxi;
            maxi = max(maxi,nums[i]);
        }
        vector<int> ans;
        // for(int i = 0;i<n;i++){
        //     cout << left[i] << " " << right[i] << endl;
        // }
        for(int i = 0;i<n;i++){
            if(nums[i] > min(left[i],right[i])) ans.push_back(nums[i]);
        }
        return ans;
    }
};