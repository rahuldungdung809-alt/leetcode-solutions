class Solution {
public:
    void reverseString(vector<char>& s) {
        // USING SWAP OPERATION
        int len=s.size();
        int left=0,right=len-1;
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        
    }
};