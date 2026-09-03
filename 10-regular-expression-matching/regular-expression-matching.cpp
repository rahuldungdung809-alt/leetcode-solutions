class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, s, p, dp);
    }

    bool solve(int i, int j, string &s, string &p,
               vector<vector<int>> &dp) {

        // Pattern finished
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Check current character
        bool match = (i < s.size() &&
                     (s[i] == p[j] || p[j] == '.'));

        // Next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // 1. Ignore x*
            bool skip = solve(i, j + 2, s, p, dp);

            // 2. Use x* for current character
            bool take = match && solve(i + 1, j, s, p, dp);

            return dp[i][j] = skip || take;
        }

        // Normal character / '.'
        if (match) {
            return dp[i][j] =
                solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = false;
        
    }
};