class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i + 1 <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = maximum number of non-overlapping
        // palindromes using s[0 ... i-1]
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't select a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every possible starting position
            for (int j = 0; j < i; j++) {

                // Check length >= k and palindrome
                if (i - j >= k && pal[j][i - 1]) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
        
    }
};