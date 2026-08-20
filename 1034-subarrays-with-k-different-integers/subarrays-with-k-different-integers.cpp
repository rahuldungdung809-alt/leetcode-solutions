class Solution {
public:
    int helper(vector<int>& nums,int k){
        if(k<0)return 0;
        unordered_map<int,int>freq;
        int left=0,count=0;
        for(int right=0;right<nums.size();right++){
            if(freq[nums[right]]==0){
                k--;
            }
            freq[nums[right]]++;
            while(k<0){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    k++;
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //OPTIMAL SOLUTION    TC:O(N)   SC:O(K)
        return helper(nums,k)-helper(nums,k-1);
        
        //BRUTE FORCE SOLUTION  TC:O(N^2)    SC:O(K)
        /*int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq;
            for(int j=i;j<n;j++){
                freq[nums[j]]++;
                if(freq.size()==k){
                    count++;
                }
                if(freq.size()>k)break;
            }
        }
        return count;*/
    }
};