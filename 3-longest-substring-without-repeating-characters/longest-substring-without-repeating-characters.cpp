class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BETTER SOLUTION 
        int n=s.size();
        int ans=0;
        int left=0;
        set<char>st;
        for(int right=0;right<n;right++){
            
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;

        // BRUTE FORCE SOLUTION TC:O(N^2)  SC:O(N)
        /*int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                if(st.count(s[j])){
                    break;
                }
                st.insert(s[j]);
                ans=max(ans,j-i+1);
            }
        }
        return ans;*/
        
    }
};