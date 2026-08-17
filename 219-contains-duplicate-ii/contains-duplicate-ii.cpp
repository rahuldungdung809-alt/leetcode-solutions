class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //OPTIMAL SOLUTION 
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(i>k){
                st.erase(nums[i-k-1]);
            }
            if(st.find(nums[i])!=st.end()){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
        //BETTER SOLUTION TC:O(N)   SC:O(N)
        /*unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                if(i-mp[nums[i]]<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;*/




        //BRUTE FORCE SOLUTION TC:O(N^2)   SC:O(1)
        /*int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if (nums[i]==nums[j] && j-i<=k){
                    return true;
                }       
            }
        }
        return false;*/        
    }
};