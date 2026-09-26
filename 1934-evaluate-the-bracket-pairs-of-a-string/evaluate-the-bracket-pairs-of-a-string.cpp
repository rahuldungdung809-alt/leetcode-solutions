class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
            }

            // Bracket pair
            else {
                i++;  // move after '('

                string key = "";

                // Collect characters until ')'
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Check if key exists
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += '?';
                }
            }
        }

        return ans;
        
    }
};