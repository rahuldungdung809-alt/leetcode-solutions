class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {         
        int n=nums.size();
        long long ans=0;
        vector<int>st;

        //Maximum contribution
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.back()]<nums[i])){
                int j=st.back();
                st.pop_back();
                int l=st.empty() ? j+1 : j-st.back();
                int r=i-j;
                ans+=1LL *nums[j]*l*r;
            }
            if(i<n)
            st.push_back(i);
        }
        st.clear();
        //Minimum contribution
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || nums[st.back()]>nums[i])){
                int j=st.back();
                st.pop_back();
                int l=st.empty() ? j+1 : j-st.back();
                int r=i-j;
                ans-=1LL *nums[j]*l*r;
            }
            if(i<n)
            st.push_back(i);
        }    
        return ans;                                                                       
                                                                                                                                                                                                                                                   


       // BRUTE FORCE TC:O(N^2) SC:O(1)
        /*long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long largest=nums[i],smallest=nums[i];
            for(int j=i+1;j<n;j++){
                largest=max(largest,(long long)nums[j]);
                smallest=min(smallest,(long long)nums[j]);
                sum+=(largest-smallest);
            }
        }
        return sum;*/
        
    }
};