class Solution {
public:
    int helper(vector<int>& nums,int k){
        if(k<0)return 0;
        int count=0;
        int left=0;
        
        for(int right=0;right<nums.size();right++){
            if(nums[right] %2==1){k--;}
            while(k<0){
                if(nums[left]%2==1){
                    k++;
                }
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //OPTIMAL SOLUTION TC:O(N)   SC:O(1)
        return helper(nums,k)-helper(nums,k-1);
        // BETTER SOLUTION TC:O(N)   SC:O(N)
        /*unordered_map<int,int>freq;
        int oddCount=0;
        int res=0;
        freq[0]=1;
        for(int num:nums){
            if(num%2==1){
                oddCount++;
            }
            if(freq.count(oddCount-k)){
                res+=freq[oddCount-k];
            }
            freq[oddCount]++;
        }
        return res;*/

        //BRUTE FORCE SOLUTION TC:O(N^2)   SC:O(1)
        /*int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int oddCount=0;
            for(int j=i;j<n;j++){
                if(nums[j] %2 != 0){
                    oddCount++;
                }
                if(oddCount>k)break;
                if(oddCount==k){
                    count++;
                }
            }

        }
        return count;*/
        
    }
};