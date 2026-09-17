class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // ending anywhere from 0 to i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;

        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // We found a subarray with sum = target
            if (sum == target) {

                int len = right - left + 1;

                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // This is the best valid subarray ending at/before right
                best[right] = len;
            }

            // Carry forward the previous best
            if (right > 0) {
                best[right] = min(best[right], best[right - 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};