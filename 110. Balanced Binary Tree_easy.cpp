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
    /**CORE IDEA: to use recursion aas used in finding the max depth 
    and then comparinmg the left and right subtree if diff id greater than 1
    if found set to false else continue with the maxDeth algo
    **/
public:
    bool isBalanced(TreeNode* root) {
        bool res=true;
        compMaxDepth(root,res);
        return res;
    }
private:
    int compMaxDepth(TreeNode* root, bool &res){
        if(root==NULL){
            return 0;
        }
        int left = compMaxDepth(root->left,res);
        int right = compMaxDepth(root->right,res);

        if (abs(left-right)>1)res=false;
        return  1+max(left,right);
    }
};
