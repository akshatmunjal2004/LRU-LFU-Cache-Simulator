#include "../include/LFUCache.h"

LFUCache::LFUCache(int cap) : capacity(cap), minFreq(0) {}

void LFUCache::updateFrequency(int key)
{
    auto node = keyNode[key];
    int freq = node->freq;
    Node newNode = *node;
    newNode.freq++;

    freqList[freq].erase(node);
    if (freqList[freq].empty())
    {
        freqList.erase(freq);
        if (minFreq == freq)
            minFreq++;
    }

    freqList[freq + 1].push_front(newNode);
    keyNode[key] = freqList[freq + 1].begin();
}

int LFUCache::get(int key)
{
    if (keyNode.find(key) == keyNode.end())
        return -1;
    updateFrequency(key);
    return keyNode[key]->value;
}

void LFUCache::put(int key, int value)
{
    if (capacity == 0)
        return;

    if (keyNode.find(key) != keyNode.end())
    {
        keyNode[key]->value = value;
        updateFrequency(key);
        return;
    }

    if (keyNode.size() >= capacity)
    {
        auto nodeToRemove = freqList[minFreq].back();
        keyNode.erase(nodeToRemove.key);
        freqList[minFreq].pop_back();
        if (freqList[minFreq].empty())
        {
            freqList.erase(minFreq);
        }
    }

    Node newNode(key, value);
    freqList[1].push_front(newNode);
    keyNode[key] = freqList[1].begin();
    minFreq = 1;
}
