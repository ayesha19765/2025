class LRUCache {
public:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node*> cache;
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);  // dummy head
        tail = new Node(0, 0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);  // Move to front (most recently used)
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;

        if (cache.size() > cap) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */