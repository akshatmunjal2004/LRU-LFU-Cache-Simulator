#include "../include/LRUCache.h"
#include "../include/LFUCache.h"
#include <iostream>

void runLRU()
{
    int cap;
    std::cout << "Enter LRU Cache Capacity: ";
    std::cin >> cap;
    LRUCache lru(cap);

    while (true)
    {
        int choice;
        std::cout << "\n1. Put\n2. Get\n3. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int key, value;
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            lru.put(key, value);
            std::cout << "Inserted (" << key << ", " << value << ")\n";
        }
        else if (choice == 2)
        {
            int key;
            std::cout << "Enter key to get: ";
            std::cin >> key;
            int val = lru.get(key);
            if (val == -1)
                std::cout << "Key not found\n";
            else
                std::cout << "Value: " << val << "\n";
        }
        else
            break;
    }
}

void runLFU()
{
    int cap;
    std::cout << "Enter LFU Cache Capacity: ";
    std::cin >> cap;
    LFUCache lfu(cap);

    while (true)
    {
        int choice;
        std::cout << "\n1. Put\n2. Get\n3. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            int key, value;
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            lfu.put(key, value);
            std::cout << "Inserted (" << key << ", " << value << ")\n";
        }
        else if (choice == 2)
        {
            int key;
            std::cout << "Enter key to get: ";
            std::cin >> key;
            int val = lfu.get(key);
            if (val == -1)
                std::cout << "Key not found\n";
            else
                std::cout << "Value: " << val << "\n";
        }
        else
            break;
    }
}

int main()
{
    int mode;
    std::cout << "Choose Cache Mode: 1 -> LRU | 2 -> LFU: ";
    std::cin >> mode;

    if (mode == 1)
        runLRU();
    else if (mode == 2)
        runLFU();
    else
        std::cout << "Invalid mode!\n";

    return 0;
}
