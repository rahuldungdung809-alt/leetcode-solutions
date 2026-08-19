class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //OPTIMAL SOLUTION TC:O(K)   SC:O(1)
        int n=cardPoints.size();
        int total=0;
        for(int i=0;i<k;i++){
            total+=cardPoints[i];
        }
        int maxPoint=total;
        for(int i=0;i<k;i++){
            total-=cardPoints[k-1-i];
            total+=cardPoints[n-1-i];
            maxPoint=max(maxPoint,total);
        }
        return maxPoint;
        //BRUTE FP\ORCE SOLUTION  TC:O(K^2)    SC:O(1)
        /*int n=cardPoints.size();
        int res=0;
        for(int i=0;i<=k;i++){
            int sum=0;
            for(int j=0;j<i;j++){
                sum+=cardPoints[j];
            }
            for(int j=n-(k-i);j<n;j++){
                sum+=cardPoints[j];
            }
            res=max(sum,res);
        }
        return res;*/
        
    }
};