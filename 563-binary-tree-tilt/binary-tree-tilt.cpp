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
    int findTilt(TreeNode* root) {
        int sum = 0;
        int val = ans(root,sum);
        return sum;
    }
    int ans(TreeNode* root,int& sum){
        if(root == NULL) return 0;
        int leftSum = ans(root->left,sum);
        int rightSum = ans(root->right,sum);
        sum += abs(leftSum-rightSum);
        // cout << sum << " ";
        return root->val + leftSum + rightSum;
    }
};