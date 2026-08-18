class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // BETTER SOLUTION TC:O(N)   SC:O(N)
        unordered_map<int,int>freq;
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
        return res;

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