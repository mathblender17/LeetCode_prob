/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
/**
CORE IDEA: 2 things are main here - 
1st -> the create a new node of each of the old graph then 
2nd -> join the new copy node with neighbors of the old node
3rd -> repeat this process this all the nodes are copied and their edges/neighbors checked
we can use both dfs or bfs to tackle this 
dfs->backtracaking with a map
bfs -> while loop with queue
**/
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldtonew;
        return dfs(node, oldtonew);

    }
    Node* dfs(Node* node,map<Node*,Node*>& oldtonew){
        if(node==nullptr){
            return nullptr;
        }
        if(oldtonew.count(node)){
            return oldtonew[node];
        }
        Node* copy =new Node(node->val);
        oldtonew[node]=copy;
        for(Node* nei : node->neighbors){
            copy->neighbors.push_back(dfs(nei,oldtonew));
        
        }
        return copy;

    }
};
