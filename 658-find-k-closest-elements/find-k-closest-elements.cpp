class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //HEAP
        priority_queue<pair<int,int>>pq;
        for(int num:arr){
            int diff=abs(num-x);
            pq.push({diff,num});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
        
        
    }
};