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
//Thanks neetcode for the explanation
/**CORE IDEA: to use preorder to get the nodes(also order) + use inorder to get the  left and righjt subtree 
take element for preorder  and store in  new treenode then recursive calls for the left and right subtree
**/
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return build(preorder,inorder,index,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &index,int i,int j){
        if(i>j)return NULL;//leaf node

        TreeNode* root=new TreeNode(preorder[index]);
        int split=0;
        for(int i=0;i<inorder.size();i++){
            if(preorder[index]==inorder[i]){
                split=i;
                break;
            }
        }
        index++;//able to keep track for each  node val 

        root->left=build(preorder,inorder,index,i,split-1);
        root->right=build(preorder,inorder,index,split+1,j);

        return root;
    }
};
