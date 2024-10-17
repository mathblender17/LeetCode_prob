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
CORE IDEA : to use recursion and swap left and right nodes of the root node 
till root==NULL then we stop
**/
    void invert(TreeNode* &root){
        if(root==NULL){
            return ;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;

        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }

};
