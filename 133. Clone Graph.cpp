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
    void visitAll(unordered_map<int, Node*> &mp, Node* node){
        Node *temp = new Node(node->val, {});
        mp[node->val] = temp;

        for(Node *nb : node->neighbors){
            if(mp.find(nb->val) == mp.end()){
                visitAll(mp, nb);
            }
        }
    }
    void addLinks(unordered_map<int, Node*> &mp, Node* node, Node *clonNode, vector<bool> &visited){
        visited[clonNode->val] = true;
        vector<Node*> temp;
        for(Node *nb : node->neighbors){
            temp.push_back(mp[nb->val]);
        }
        clonNode->neighbors = temp;
        for(Node *nb : node->neighbors){
            if(!visited[nb->val]){
                addLinks(mp, nb, mp[nb->val], visited);
            }
        }        
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return node;
        
        unordered_map<int, Node*> mp;
        
        visitAll(mp, node);
        
        vector<bool> visited(mp.size() + 1, false);
        
        addLinks(mp, node, mp[1], visited);

        return mp[1];
    }
};