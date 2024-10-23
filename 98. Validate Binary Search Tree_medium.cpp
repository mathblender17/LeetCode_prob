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
//CORE IDEA: to use properties of BST with DFS style
//(also BST in inorder is strictly increasing)
    bool isValidBST(TreeNode* root) {
        return help(root,LONG_MIN,LONG_MAX);//long ised to take edge cases into acc and prevent out of bound that may happen with int

    }
    bool help(TreeNode* root,long left,long right){
        if(root==NULL)return true;//empty node is a valid BST
        if(root->val>left && root->val<right){
            //recursively check ofr leftr and right subtree- for valid BST
            return help(root->left,left,root->val) && help(root->right,root->val,right);

        }
        return false;//if both aboce conditons not satisfied then return false
    }
};
