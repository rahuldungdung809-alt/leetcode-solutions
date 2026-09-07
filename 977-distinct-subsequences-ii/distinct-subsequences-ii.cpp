class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        vector<long long> last(26, 0);

        long long total = 1;  // empty subsequence

        for (char c : s) {
            int idx = c - 'a';

            long long newSubseq = total;

            // Remove subsequences already created by this character
            total = (total + newSubseq - last[idx] + MOD) % MOD;

            last[idx] = newSubseq;
        }

        // Remove the empty subsequence
        return (total - 1 + MOD) % MOD;
        
    }
};