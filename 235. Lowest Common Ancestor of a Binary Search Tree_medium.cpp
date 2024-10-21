/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
// check for the node values < , > 
// if the val is greater than both go to left tree
// of leess got to right 
//if in betwen record the val 
// nad go to the left tree - > do the same keep a check for min value of the LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //int minLCA=INT_MAX;
        if(root->val > p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            //minLCA=min(root->val,minLCA);
            return root;
        }
    }
};
