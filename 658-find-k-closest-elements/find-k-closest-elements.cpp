class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //SLIDING WINDOW + BINARY SEARCH
        int left=0;
        int right=arr.size()-k;
        while(left<right){
            int mid=left+(right-left)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
        //HEAP TC:O(N LOG N)   SC:O(K)
        /*priority_queue<pair<int,int>>pq;
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
        return res;*/
        
        
    }
};