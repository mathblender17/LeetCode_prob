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
    /**CORE IDEA: BFS search to traverse the binary tree + to take the rightmost element 
    to do this add the right side child frirst and take only the front() element from the queue
    **/
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int> res;

        while(!q.empty()){
            int size = q.size();

            for(int i=size;i>0;i--){
                TreeNode* node =q.front();
                q.pop();

                if(i==size){
                    res.push_back(node->val);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                if(node->left != NULL){
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};
