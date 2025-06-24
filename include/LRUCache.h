#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>

class LRUCache
{
private:
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void addNode(Node *node);
    void removeNode(Node *node);
    void moveToHead(Node *node);
    Node *popTail();

public:
    LRUCache(int cap);
    ~LRUCache();
    int get(int key);
    void put(int key, int value);
};

#endif
