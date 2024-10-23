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
//CORE IDEA: Something like dfs with a maxInpath to keep the count of the max val in the path 
// done this withthe help of help function
    int goodNodes(TreeNode* root) {
        return help(root,INT_MIN);
    }
    int help(TreeNode* root,int maxInPath){
        if(root==NULL)return 0;
        int res=0;
        if(root->val>=maxInPath){
            res=1;//to check if the current node is a good Node
        }
        maxInPath=max(root->val,maxInPath);//maInPath updated
        //to calc the res = res(1 or 0) + res_of left_subtree + res_of right_subtree
        res+=help(root->left,maxInPath)+help(root->right,maxInPath);

        return res;
    }
};
