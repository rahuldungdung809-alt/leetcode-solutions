class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long XorAll=0;
        for(int i=0;i<n;i++){
            XorAll^=nums[i];
        }
        long difBit=XorAll & (-XorAll);
        int a=0,b=0;
        for(int x:nums){
            if(x & difBit){
                a^=x;
            }
            else{
                b^=x;}
        }
        return {a,b};




















        /*long xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr^=nums[i];
        }
        long rightmost = xorr & (-xorr);
        int b1=0,b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & rightmost){
                b1 ^ = nums[i];
            }
            else{
                b2 ^ = nums[i];
            }
        }
        return {b1,b2};*/
    }
};