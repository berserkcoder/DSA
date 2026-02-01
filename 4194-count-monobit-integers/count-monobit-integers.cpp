class Solution {
public:
    int countMonobit(int n) {
        int count = 1;
        for(int i = 1;i<=n;i++){
            int val = i%2;
            int value = i;
            bool flag = true;
            while(value != 0){
                if(value % 2 != val) {
                    flag = false;
                    break;
                }
                value = value/2;
            }
            if(flag) count++;
        }
        return count;
    }
};