/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    pair<int, int> solve(TreeNode* root) {
        
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count of left subtree
        pair<int, int> left = solve(root->left);

        // Get sum and count of right subtree
        pair<int, int> right = solve(root->right);

        // Current subtree sum
        int sum = root->val + left.first + right.first;

        // Current subtree node count
        int count = 1 + left.second + right.second;

        // Average of current subtree
        int average = sum / count;

        if (average == root->val) {
            ans++;
        }

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);

        return ans;
        
    }
};