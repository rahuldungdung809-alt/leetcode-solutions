class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxWater=0;
        int n=height.size();
        int lp=0,rp=n-1;
        while(lp<rp){
           
            int ht=min(height[lp],height[rp]);
            int w=rp-lp;
            
            MaxWater=max(ht*w,MaxWater);
            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
            
        }
        
        return MaxWater;
        
    }
};