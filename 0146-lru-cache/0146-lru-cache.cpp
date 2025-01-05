class LRUCache {
  public:
    // Node class to represent each entry in the doubly linked list
    class node {
      public:
        int key;  // key of the cache entry
        int val;  // value of the cache entry
        node *next;  // pointer to the next node
        node *prev;  // pointer to the previous node
        node(int _key, int _val) {
          key = _key;
          val = _val;
        }
    };

    node *head = new node(-1, -1);  // Dummy head node
    node *tail = new node(-1, -1);  // Dummy tail node

    int cap;  // Capacity of the cache
    unordered_map<int, node *> m;  // Hashmap to store key-value pairs

    // Constructor to initialize the cache with the given capacity
    LRUCache(int capacity) {
      cap = capacity;
      head->next = tail;  // Head's next points to tail
      tail->prev = head;  // Tail's previous points to head
    }

    // Function to add a node to the front of the doubly linked list
    void addnode(node *newnode) {
      node *temp = head->next;
      newnode->next = temp;
      newnode->prev = head;
      head->next = newnode;
      temp->prev = newnode;
    }

    // Function to delete a node from the doubly linked list
    void deletenode(node *delnode) {
      node *delprev = delnode->prev;
      node *delnext = delnode->next;
      delprev->next = delnext;  // Connect the previous node to the next node
      delnext->prev = delprev;  // Connect the next node to the previous node
    }

    // Function to get the value of a key from the cache
    int get(int key_) {
      if (m.find(key_) != m.end()) {  // If the key exists in the cache
        node *resnode = m[key_];
        int res = resnode->val;  // Get the value
        m.erase(key_);  // Remove the key-value pair from the map
        deletenode(resnode);  // Remove the node from the doubly linked list
        addnode(resnode);  // Add the node to the front (most recently used)
        m[key_] = head->next;  // Update the map with the new position of the node
        return res;  // Return the value
      }

      return -1;  // If the key is not found, return -1
    }

    // Function to insert a key-value pair into the cache
    void put(int key_, int value) {
      if (m.find(key_) != m.end()) {  // If the key exists in the cache
        node *existingnode = m[key_];
        m.erase(key_);  // Remove the key-value pair from the map
        deletenode(existingnode);  // Remove the node from the doubly linked list
      }

      // If the cache is full, remove the least recently used (LRU) node
      if (m.size() == cap) {
        m.erase(tail->prev->key);  // Remove the key from the map
        deletenode(tail->prev);  // Remove the node from the doubly linked list
      }

      // Add the new key-value pair as the most recently used node
      addnode(new node(key_, value));
      m[key_] = head->next;  // Update the map with the new node
    }
};

/*
### Time Complexity:
- **get()**: O(1)
  - Hashmap lookup is O(1).
  - Deletion and insertion of a node in the doubly linked list are both O(1).
- **put()**: O(1)
  - Hashmap operations (lookup, insertion, and deletion) are O(1).
  - Deletion and insertion of a node in the doubly linked list are O(1).
  
Overall, both get() and put() operations have constant time complexity.

### Space Complexity:
- **O(cap)**: 
  - The space complexity is determined by the number of elements in the cache, which is limited by the capacity (`cap`).
  - The cache stores up to `cap` nodes in the doubly linked list, and the hashmap stores the same number of key-value pairs.

### Explanation:
- This LRU Cache uses a combination of a doubly linked list and a hashmap.
  - The doubly linked list maintains the order of elements, with the most recently used node at the front and the least recently used at the back.
  - The hashmap allows constant time access to the nodes by their keys.
- The `get()` method retrieves a value and moves the corresponding node to the front (making it the most recently used).
- The `put()` method inserts a new key-value pair and ensures the cache size does not exceed its capacity. If the cache is full, it removes the least recently used node.
*/
