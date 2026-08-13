class Node {
public:
    int key, val;
    Node* next;
    Node* prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = prev = NULL;
    }
};

void insertNode(Node* head, Node* node) {
    Node* after = head->next;

    head->next = node;
    node->prev = head;

    node->next = after;
    after->prev = node;
}

void deleteNode(Node* node) {
    Node* prevN = node->prev;
    Node* nextN = node->next;

    prevN->next = nextN;
    nextN->prev = prevN;
}

class LRUCache {
public:
    unordered_map<int, Node*> mmp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mmp.find(key) == mmp.end()) {
            return -1;
        }

        Node* node = mmp[key];

        // Remove from current position
        deleteNode(node);

        // Put at front = most recently used
        insertNode(head, node);

        return node->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mmp.find(key) != mmp.end()) {

            Node* node = mmp[key];

            deleteNode(node);

            node->val = value;

            insertNode(head, node);

        } else {

            // Cache is full
            if (mmp.size() == capacity) {

                Node* node = tail->prev;

                mmp.erase(node->key);

                deleteNode(node);

                delete node;
            }

            Node* node = new Node(key, value);

            insertNode(head, node);

            mmp[key] = node;
        }
    }
};