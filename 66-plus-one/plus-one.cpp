class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size()-1] =  digits[digits.size()-1] + 1;
        carry =  digits[digits.size()-1]/10;
        int i = digits.size()-2;
        if(carry == 1){
            digits[i+1] = 0;
        }
        while(carry == 1 && i >=0){
            digits[i] = digits[i] + carry;
            carry = digits[i]/10;
            if(digits[i] >= 10) digits[i] = 0;
            i--;
        }
        if(carry == 1){
            digits.push_back(carry);
            for(int j = digits.size()-1;j>=1;j--){
                int temp = digits[j];
                digits[j] = digits[j-1];
                digits[j-1] = temp;  
            }
        }
        return digits;
    }
};