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
/**CORE IDEA: to do a BFS travaersal to get node elements at each level
qeue of Treenpde* is used to traverse - iterative approach
**/
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root==NULL) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int>curr;

            for(int i=0;i<s;i++){
                TreeNode* top=q.front();
                q.pop();
                curr.push_back(top->val);

                if(top->left != NULL){
                    q.push(top->left);
                }
                if(top->right !=NULL){
                    q.push(top->right);
                }
            }
            res.push_back(curr);
            
        }
        return res;

    }
};
