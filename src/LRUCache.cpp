#include "../include/LRUCache.h"

LRUCache::LRUCache(int cap)
{
    capacity = cap;
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
}

LRUCache::~LRUCache()
{
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
}

void LRUCache::addNode(Node *node)
{
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void LRUCache::removeNode(Node *node)
{
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
}

void LRUCache::moveToHead(Node *node)
{
    removeNode(node);
    addNode(node);
}

LRUCache::Node *LRUCache::popTail()
{
    Node *res = tail->prev;
    removeNode(res);
    return res;
}

int LRUCache::get(int key)
{
    if (cache.find(key) != cache.end())
    {
        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }
    return -1;
}

void LRUCache::put(int key, int value)
{
    if (cache.find(key) != cache.end())
    {
        Node *node = cache[key];
        node->value = value;
        moveToHead(node);
    }
    else
    {
        Node *newNode = new Node(key, value);
        cache[key] = newNode;
        addNode(newNode);

        if (cache.size() > capacity)
        {
            Node *tailNode = popTail();
            cache.erase(tailNode->key);
            delete tailNode;
        }
    }
}
