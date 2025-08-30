class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> flag(n+1,0);
        vector<int> per;
        permutations(n,flag,per,0);
        sort(per.begin(),per.end());
        return to_string(per[k-1]);
    }
    void permutations(int n,vector<int>& flag,vector<int>& per,int sum){
        if(n == 0){
            per.push_back(sum);
            return;
        }
        for(int i = 1;i<flag.size();i++){
            if(flag[i] == 0){
                flag[i] = 1;
                sum = sum * 10 + i;
                permutations(n-1,flag,per,sum);
                sum = sum / 10;
                flag[i] = 0;
            }
        }
    }
};