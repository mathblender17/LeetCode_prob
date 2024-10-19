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
CORE IDEA : traverse through the nodes in the root BT
if found return true
if not go to another node left and right (only one of the has to be true for all  of  it to be true) i.e subtree exists
checking done in the same way as that for checking 2 trees 
**/
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        
        if(isSame(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    

        
    }
    bool isSame(TreeNode* r, TreeNode* s){
        if(r==NULL && s==NULL)return true;
        if(r==NULL || s==NULL)return false;
        if(r->val!=s->val)return false;
        return  isSame(r->left,s->left) && isSame(r->right,s->right);
    }
};
