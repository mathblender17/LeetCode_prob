/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
/** CORE IDEA: to use dfs to serlize it into a string vector then to a string using a join funciton
and to deserlize use the string and split it into a string vector and from there construct a tree - samne dfs
We make use of splir and join function to do the internal conversion  
- stringstream is used and some m\y allocation 
**/
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSer(root,res);
        return join(res,",");
    }
    void dfsSer(TreeNode* root,vector<string>& res){
        if(root==NULL){
            res.push_back("N");
            return ;
        }
        res.push_back(to_string(root->val));
        dfsSer(root->left,res);
        dfsSer(root->right,res);
    }
    string join(const vector<string> &v, const string &delim){
        ostringstream s;
        for(const auto &i:v){
            if(&i != &v[0])s<<delim;
            s<<i;
        }
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data,',');
        int i=0;
        return dfsDeser(vals,i);
    }
    TreeNode* dfsDeser(vector<string>& vals,int &i){
        if(vals[i]=="N"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left=dfsDeser(vals,i);
        node->right=dfsDeser(vals,i);

        return node;
    }
    vector<string> split(const string &data , char delim){
        stringstream ss(data);
        vector<string> res;
        string item;
        while(getline(ss,item,delim)){
            res.push_back(item);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
