class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        bool flag = false;
        int front = 1;
        int back = n;
        while(k > 0){
            if(flag == false){
                ans.push_back(front);
                front++;
                k--;
                flag = true;
            }else {
                ans.push_back(back);
                back--;
                k--;
                flag = false;
            }
        }
        if(flag){
            for(int i = front;i<=back;i++) ans.push_back(i);
        }else{
            for(int i = back;i>=front;i--) ans.push_back(i);
        }
        return ans;
    }
};