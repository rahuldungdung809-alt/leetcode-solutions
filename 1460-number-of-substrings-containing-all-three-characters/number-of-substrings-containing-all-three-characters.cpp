class Solution {
public:
    int numberOfSubstrings(string s) {
        //OPTIMAL SOLUTION 
        vector<int>freq(3,0);
        int res=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                res+=(s.length()-right);
                freq[s[left]-'a']--;
                left++;
            }
        }
        return res;
        //BRUTE FORCE SOLUTION TC:O(N^2)      SC:O(1)
        /*int count=0;
        for(int i=0;i<s.length();i++){
            vector<int>freq(3,0);
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                if(freq[0] > 0 && freq[1]>0 && freq[2]>0){
                    count++;
                }
            }

        }
        return count;*/
        
    }
};