#include <unordered_map>

using namespace std;

// ------------------------------
// Doubly Linked List Node
// ------------------------------
class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value)
        : key { key }, value { value }, next { nullptr }, prev { nullptr }
    {}
};

// ------------------------------
// Doubly Linked List
// ------------------------------
class DoublyLinkedList
{
public:
    int size;
    Node *head; // Dummy handle node
    Node *tail; // Dummy handle node

    DoublyLinkedList() : size { 0 }
    {
        head = new Node { -1, -1 };
        tail = new Node { -1, -1 };
        head->next = tail;
        tail->prev = head;
    }
    ~DoublyLinkedList()
    {
        // Clean up all nodes
        Node *current = head;
        while (current != nullptr) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Time: O(1)
    void push_front(Node *newNode)
    {
        // Head <-> first <-> .... <-> Tail
        Node *first = head->next;

        // Head <- newNode -> first <-> .... <-> Tail
        newNode->next = first;
        newNode->prev = head;
        // Head <-> newNode <-> first <-> .... <-> Tail
        head->next = newNode;
        first->prev = newNode;

        size += 1;
    }

    // Time: O(1)
    void push_back(Node *newNode)
    {
        // Head <-> .... <-> last <-> Tail
        Node *last = tail->prev;

        // Head <-> .... <-> last <- newNode -> Tail
        newNode->prev = last;
        newNode->next = tail;
        // Head <-> .... <-> last <-> newNode <-> Tail
        last->next = newNode;
        tail->prev = newNode;

        size += 1;
    }

    // Time: O(1)
    Node *pop_front()
    {
        // Must have atleast 1 node
        if (size == 0)
            return nullptr;

        Node *target = head->next;
        pop_target(target);
        return target;
    }

    // Time: O(1)
    Node *pop_back()
    {
        if (size == 0)
            return nullptr;

        Node *targetNode = tail->prev;
        pop_target(targetNode);
        return targetNode;
    }

    // Time: O(1)
    void pop_target(Node *targetNode)
    {
        if (size == 0 || targetNode == head || targetNode == tail)
            return;

        // nxt <-> target <-> prv
        Node *nxt = targetNode->next;
        Node *prv = targetNode->prev;

        // nxt <-> prv
        prv->next = nxt;
        nxt->prev = prv;

        // nxt <-> prv |  targetNode
        targetNode->next = nullptr;
        targetNode->prev = nullptr;

        // Update size
        size -= 1;
    }
};

// --------------------
// LRU Cache
// --------------------
class LRUCache
{
private:
    DoublyLinkedList *cache;
    unordered_map<int, Node *> hashMap;
    int capacity;

public:
    // Space: O(n), where n is the capacity
    LRUCache(int capacity) : capacity { capacity }
    {
        cache = new DoublyLinkedList {};
    }

    ~LRUCache()
    {
        delete cache;
        cache = nullptr;
    }

    // Time: O(1)
    int get(int key)
    {
        // key doesn't exist
        if (hashMap.find(key) == hashMap.end())
            return -1;

        Node *node = hashMap[key];
        // Move the node to the front (most recently used)
        cache->pop_target(node);
        cache->push_front(node);

        return node->value;
    }

    // Time: O(1)
    void put(int key, int value)
    {
        // Key already exists
        if (hashMap.find(key) != hashMap.end()) {
            Node *node = hashMap[key];
            node->value = value;
            // Add new node to Cache
            cache->pop_target(node);
            cache->push_front(node);
            return;
        }

        // LRU full capacity
        if (cache->size == capacity) {
            // Delete LRNode from cache
            Node *leastRecentNode = cache->pop_back();

            // Delete LRNode from hashmap
            hashMap.erase(leastRecentNode->key);

            delete leastRecentNode;
        }

        Node *newNode = new Node { key, value }; // Create new Node
        cache->push_front(newNode);              // add new Node to cache
        hashMap[key] = newNode;                  // add new Node to hashmap
    }
};
