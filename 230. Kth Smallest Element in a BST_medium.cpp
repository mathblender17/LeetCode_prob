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
/**CORE IDEA : inorder traversal in BST is strictly inreassiung + count down from k till it k==0 then returnt the cuur node/root
**/
    int kthSmallest(TreeNode* root, int k) {
        //traversal is done good when with a help functoin
        int result =0;
        inorder(root,k,result);
        return result;
    }
    void inorder(TreeNode* &root,int &k,int &result){
        if(root==NULL)return;

        inorder(root->left,k,result);
        k--;
        if(k==0){
            result=root->val;
            return ;
        }
        inorder(root->right,k,result);
    }
};
