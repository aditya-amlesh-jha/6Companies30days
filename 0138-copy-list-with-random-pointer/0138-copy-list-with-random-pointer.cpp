/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> map;
        Node *newNode = new Node(-1);
        Node *tail = newNode;
        
        
        while(head){
            if(!map.count(head)){
                map[head] = new Node(head->val);
            }
            if(head->next && !map.count(head->next)){
                map[head->next] = new Node(head->next->val);
            }
            if(head->random && !map.count(head->random)){
                map[head->random] = new Node(head->random->val);
            }
            
            tail->next = map[head];
            tail = tail->next;
            tail->next = map[head->next];
            tail->random = map[head->random];
            
            head = head->next;
        }
        
        return newNode->next;
    }
};