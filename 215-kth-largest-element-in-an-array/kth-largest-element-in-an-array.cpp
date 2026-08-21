class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater <int>>pq;
        for(int x:nums){
            pq.push(x);

            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();

        //SIMPLE APPROACH TC:O(N LOG N)   SC:O(1)
        /*sort(nums.begin(),nums.end());
        return nums[nums.size()-k];*/
        
    }
};