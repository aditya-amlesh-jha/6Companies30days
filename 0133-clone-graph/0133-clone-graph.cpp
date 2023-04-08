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
    unordered_map<int,Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return node;
        }
        else if(map.count(node->val)){
            return map[node->val];
        }
        Node *newNode = new Node(node->val);
        map[node->val] = newNode;
        for(int i=0;i<node->neighbors.size();i++){
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};