class Solution {
public:
    int helper(vector<int>& nums,int goal){
        if(goal<0)return 0;
        int left=0,right=0,count=0,sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //OPTIMAL SOLUTION 
        return helper(nums,goal)-helper(nums,goal-1);

        //BETTER SOLUTION TC:O(N)   SC:O(N)
        /*unordered_map<int,int>prefixSum;
        int sum=0,count=0;
        prefixSum[0]=1;
        for(int num:nums){
            sum+=num;
            if(prefixSum.find(sum-goal)!=prefixSum.end()){
                count+=prefixSum[sum-goal];
            }
            prefixSum[sum]++;
        }
        return count;*/

        //BRUTE FORCE SOLUTION  TC:O(N^2)   SC:O(1)
    /*int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==goal){
                    count++;
                }
            }

        }
        return count;*/
        
    }
};