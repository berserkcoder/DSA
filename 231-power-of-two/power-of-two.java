class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }else if (n==0){
            return false;
        }
        return (boolean)(n%2==0) && isPowerOfTwo(n/2);
    }
}