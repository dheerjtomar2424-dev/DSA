class LRUCache {
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

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

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!mp.count(key))
            return -1;

        Node* node = mp[key];
        remove(node);
        insert(node);

        return node->val;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }

        if (mp.size() == cap) {
            Node* node = tail->prev;
            mp.erase(node->key);
            remove(node);
            delete node;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);
    }
};