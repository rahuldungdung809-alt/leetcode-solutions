class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(n>m){
            return "";
        }
        vector<int>mp(128,0);
        for(char c:t){
            mp[c]++;
        }
        int left=0;
        int count=n;
        int minLen=INT_MAX;
        int start=0;
        for(int right=0;right<m;right++){
            if(mp[s[right]]>0){
                count--;
            }
            mp[s[right]]--;
            while(count==0){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0){
                    count++;
                }
                left++;
            }
        }
        return minLen==INT_MAX ?"":s.substr(start,minLen);



        
        /*unordered_map<char, int> need, window;

        // Store frequency of characters in t
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;

        int required = need.size();
        int formed = 0;

        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            char c = s[right];

            // Add current character to window
            window[c]++;

            // Check if this character's required frequency is satisfied
            if (need.count(c) && window[c] == need[c]) {
                formed++;
            }

            // Try to shrink the window
            while (left <= right && formed == required) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];

                // Remove left character
                window[leftChar]--;

                // If requirement is no longer satisfied
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);*/
        
    }
};