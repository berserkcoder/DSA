class Solution {
public:
    bool isBalanced(string num) {
        int sumEven = 0;
        int sumOdd = 0;
        for(int i = 0;i<num.size();i++){
            if(i % 2 == 0){
                sumEven += (int)(num[i])-48;
            }else {
                sumOdd += (int)(num[i])-48;
            }
        }
        return sumEven == sumOdd;
    }
};