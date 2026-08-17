class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //OPTIMAL SOLUTION 
        int left=0;
        int zero=0;
        int maxlen=0;

        for (int right=0;right<nums.size();right++){
            if (nums[right]==0){
                zero++;
            }
            if(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
        //BETTER SOLUTION TC:O(N)  SSC:O(1) 
        /*int left=0;
        int maxlen=0;
        int zero=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                zero++;
            }
            while(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;

            }
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;*/


        //BRUTE FORCE SOLUTION TC:O(N^2)  SC:O(1)
        /*int maxLen=0;
        for(int i=0;i<nums.size();i++){
            int zero=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==0){
                    zero++;
                }
                if(zero>k){break;}
                maxLen=max(maxLen,j-i+1);
            }
        }
        return maxLen;*/
        
    }
};