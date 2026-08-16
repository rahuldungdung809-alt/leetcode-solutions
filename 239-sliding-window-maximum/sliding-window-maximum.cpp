class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //BETTER APPROACH USING HASH MAP
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            if(i>=k-1){
                ans.push_back(pq.top().first);
            }
        }
        return ans;
        
        // BRUTE FORCE SOLUTION TC:O(N*K) SC:O(1)
        /*vector<int>ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++){
            int maxi=INT_MIN;
            for (int j=i;j<i+k;j++){
                maxi=max(maxi,nums[j]);
            }
            ans.push_back(maxi);

        }
        return ans;*/
        
    }
};