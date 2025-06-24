#ifndef LFUCACHE_H
#define LFUCACHE_H

#include <unordered_map>
#include <list>

class LFUCache
{
private:
    struct Node
    {
        int key, value, freq;
        Node(int k, int v) : key(k), value(v), freq(1) {}
    };

    int capacity;
    int minFreq;
    std::unordered_map<int, std::list<Node>::iterator> keyNode;
    std::unordered_map<int, std::list<Node>> freqList;

    void updateFrequency(int key);

public:
    LFUCache(int cap);
    int get(int key);
    void put(int key, int value);
};

#endif
