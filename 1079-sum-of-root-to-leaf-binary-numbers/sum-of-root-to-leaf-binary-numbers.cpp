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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        rec(root,"",sum);
        return sum;
    }
    void rec(TreeNode* root,string s,int& sum){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            s = s + to_string(root->val);
            int val = 1;
            int num = 0;
            for(int i = s.size()-1;i>=0;i--){
                if(s[i] == '1'){
                    num += val;
                }
                val = val*2;
            }
            sum += num;
            return;
        }
        rec(root->left,s + to_string(root->val), sum);
        rec(root->right,s + to_string(root->val),sum);
    }
};