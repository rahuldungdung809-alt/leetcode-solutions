class Solution {
public:
    int minMoves(vector<int>& nums) {

        int maxi = nums[0];

        // Find maximum element
        for (int num : nums) {
            maxi = max(maxi, num);
        }

        int ans = 0;

        // Calculate total operations
        for (int num : nums) {
            ans += maxi - num;
        }

        return ans;
    }
};