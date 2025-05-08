struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, ListNode*> key_node_map;
    ListNode* head;
    ListNode* tail;

    void deleteNode(ListNode* node) {
        key_node_map.erase(node->key);
        if (node->next != nullptr) node->next->prev = node->prev;
        if (node->prev != nullptr) node->prev->next = node->next;
        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;
        delete node;
    }

    void addKeyToBack(int key, int value) {
        ListNode* new_node = new ListNode();
        new_node->key = key;
        new_node->val = value;
        new_node->prev = tail;
        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        key_node_map[key] = new_node;
    }


public:
    // https://en.cppreference.com/w/cpp/language/default_initialization
    // in c++, pointers are default initialized to an indeterminate value,
    // not nullptr. therefore we should specify.
    // however, objects like unordered_map are initialized to a default value.
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {
        // The LRU cache seems pretty similar to a hash map.
        // the only difference is that there's a size,
        // and when the size is reached, we need a way of removing
        // the least recently used key. so we need to keep track of
        // the order of key insertions.
        // my initial idea is to use a hash map.
        // the map will map to a linked list, where the head is the
        // least recently used value.
    }

    int get(int key) {
        auto search = key_node_map.find(key);
        if (search == key_node_map.end()) return -1;
        int value = key_node_map[key]->val;
        deleteNode(key_node_map[key]);
        addKeyToBack(key, value);
        return value;
    }

    void put(int key, int value) {
        auto search = key_node_map.find(key);
        if (search != key_node_map.end()) deleteNode(key_node_map[key]);
        addKeyToBack(key, value);
        if (key_node_map.size() > capacity) {
            deleteNode(head);
        }
    }
};

// SINGLY LINKED LIST VERSION:


    // void removeNode(ListNode* node) {
    //     // removing a node:
    //     // make sure head, tail are updated properly.
    //     // remove the k,v from key_node_map.
    //     // make sure the previous node points to the next node.
    //     // in a singly linked list we can do this by
    //     // copying the data from next and deleting next.
    //     // (remember to update key_node_map)
    //     if (node == head) {
    //         head = head->next;
    //     }
    //     key_node_map.erase(node->key);

    // }

    // void addToBack(ListNode* node) {
    //     // helper fn to add node to back (least recently used)
    // }

    // int get(int key) {
    //     auto search = key_node_map.find(key);
    //     return (search == key_node_map.end()) ? -1 : search->second->val;
    // }

    // void put(int key, int value) {
    //     auto search = key_node_map.find(key);
    //     if (search == key_node_map.end()) {
    //         // case 1: if key isn't in the map, then add it to the end.
    //         if (capacity == key_node_map.size()) {
    //             // if the map is at capacity, first remove the first element.
    //             int head_key = head->key;
    //             head = head->next;
    //             key_node_map.erase(head_key);
    //         }
    //     } else {
    //         // case 2: if key is in the map, then update val, then move to tail
    //         // actually since we insert the key at the end we can just delete it here
    //         // normally, deleting in a singly linked list would be a o(n) operation,
    //         // which is unacceptable for this problem.
    //         // we could use a doubly linked list to solve this, which is the recommended solution.
    //         // but there's a clever way to delete from a linked list without searching.
    //         // basically we just copy the next node into the current node.
    //         ListNode* curr = key_node_map[value];
    //         if (curr->next != nullptr) {
    //             removeMiddleNode()
    //         } else {
    //             curr->val = value;
    //             return; // this ensures the length of the list stays the same
    //         }
    //     }

    //     // add the value to the end of the list
    //     ListNode* new_tail = new ListNode(key, value);
    //     tail->next = new_tail;
    //     tail = new_tail;
    //     key_node_map[key] = new_tail;
    // }
