class Solution {
public:

    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M, int n) {
        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int total = suffix[i];
        int best = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            int opponent = solve(i + x, max(M, x), n);

            // Stones we can get = total remaining - opponent's best
            best = max(best, total - opponent);
        }

        return dp[i][M] = best;
    }
    int stoneGameII(vector<int>& piles) {
         int n = piles.size();

        suffix.resize(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1, n);
    }
};