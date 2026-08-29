class Solution {
public:
    int jump(vector<int>& nums) {
        int low=0;
        int lnext=0;
        int maxJump=0;
        for(int i=0;i<nums.size()-1;i++){
            maxJump=max(maxJump,i+nums[i]);
            if(i==lnext){
                low++;
                lnext=maxJump;
            }
        }
        return low;
        
    }
};