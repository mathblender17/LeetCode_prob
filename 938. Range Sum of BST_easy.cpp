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
2 step 
1. traversimng a BST tree ( resccursion)
2. checking condition and adding
**/
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=low+high;
        dfs(root,low,high,sum);
        return sum;
    }
private:
    void dfs(TreeNode* node, int low, int high, int& sum){
        if(node == nullptr)return ;
        if(low < node->val && high > node->val){
            sum+=node->val;
        }
        if(low < node->val){
            dfs(node->left,low,high,sum);
        }
        if(high > node->val){
            dfs(node->right,low,high,sum);
        }
    }    
};
