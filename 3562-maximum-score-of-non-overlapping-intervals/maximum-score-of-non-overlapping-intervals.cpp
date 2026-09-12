class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        struct Interval {
            int l, r, w, idx;
        };

        vector<Interval> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by starting position
        sort(a.begin(), a.end(), [](const Interval& x,
                                    const Interval& y) {
            if (x.l != y.l)
                return x.l < y.l;
            return x.r < y.r;
        });

        // dp[i][k] = best answer using intervals from i onward,
        // choosing at most k intervals.
        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        // Binary search: first interval whose left > current right
        auto nextIndex = [&](int r) {
            int lo = 0, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid].l > r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            return lo;
        };

        // Compare two candidate answers
        auto better = [&](const Node& x, const Node& y) {
            if (x.score != y.score)
                return x.score > y.score;

            // Lexicographically smaller indices
            return x.ids < y.ids;
        };

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: skip current interval
                Node skip = dp[i + 1][k];

                // Option 2: take current interval
                Node take;

                int nxt = nextIndex(a[i].r);

                take.score = a[i].w;

                if (k > 1) {
                    take.score += dp[nxt][k - 1].score;
                    take.ids = dp[nxt][k - 1].ids;
                }

                take.ids.push_back(a[i].idx);

                // Sort indices because final answer must be
                // lexicographically compared by original indices.
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].ids;
    }
};