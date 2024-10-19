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
/**CORE IDEA: check if the 2 BT are same
3 base case + accumalating result (check the compared trees or subtrees and return that result that result instead)
**/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true; // both empty
        if(p==NULL || q==NULL)return false;// one empty
        if(p->val != q->val){//value not mathing(not empty)
            return false;
        }
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};
