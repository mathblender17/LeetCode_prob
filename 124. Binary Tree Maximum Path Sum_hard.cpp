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
/**
CORE IDEA : we find and iterate through the paths with the help form dfs (optimised - once traversal - no need to to it for each node)

**/
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root,res);
        return res;
    }
    int  dfs(TreeNode* root, int &res){
        if(!root) return 0;

        int leftMax=max(dfs(root->left,res),0);
        int rightMax=max(dfs(root->right,res),0);

        res=max(res,root->val + leftMax + rightMax);
        return root->val + max(leftMax,rightMax);
    }
};
