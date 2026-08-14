class LRUCache {
public:
    class DoublyLL {
    public:
        int key;
        int value;
        DoublyLL* next;
        DoublyLL* prev;

        DoublyLL(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    map<int, DoublyLL*> mp;
    DoublyLL* head;
    DoublyLL* tail;
    int maxi;

    LRUCache(int capacity) {
        maxi = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void addToBack(DoublyLL* node) {
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void removeNode(DoublyLL* node) {
        if (node->prev != nullptr)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next != nullptr)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        DoublyLL* node = mp[key];

        // Move it to the back because it was recently used
        removeNode(node);
        addToBack(node);

        return node->value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            DoublyLL* node = mp[key];

            node->value = value;

            // Move to back because it is recently used
            removeNode(node);
            addToBack(node);

            return;
        }

        // Cache is full -> remove LRU (head)
        if (mp.size() == maxi) {
            DoublyLL* node = head;

            removeNode(node);
            mp.erase(node->key);

            delete node;
        }

        // Add new node as MRU
        DoublyLL* node = new DoublyLL(key, value);

        addToBack(node);
        mp[key] = node;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna