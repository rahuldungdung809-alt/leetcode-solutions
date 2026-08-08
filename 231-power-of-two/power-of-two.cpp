class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & (n-1)) ==0;
        /*
        if (n & (n-1)==0){
            return true;
        }*/
        
    }
};