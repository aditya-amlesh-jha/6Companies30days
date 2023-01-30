class Node{
    public:
    int key,value;
    Node *next,*prev;
    Node(int _key, int _value){
        key = _key;
        value = _value;
        next = prev = nullptr;
    }
};



class LRUCache {
    Node *head, *tail;
    int size,capacity;
    unordered_map<int,Node*> map;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.count(key) == 0){
            return -1;
        }
        int val = map[key]->value;
        deleteNode(map[key]);
        map[key] = insertNode(key,val);
        return val;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            deleteNode(map[key]);
            map[key] = insertNode(key,value);
        }
        else if(size < capacity){
            map[key] = insertNode(key,value);
            size++;
        }
        else if(size == capacity){
            map.erase(head->next->key);
            deleteNode(head->next);
            map[key] = insertNode(key,value);
        }
    }
    void deleteNode(Node *node){
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    Node *insertNode(int key, int value){
        Node *newNode = new Node(key,value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        tail->prev = newNode;
        newNode->next = tail;
        return newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */