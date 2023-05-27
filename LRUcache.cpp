#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
using namespace std;
class LRUCache
{
    class Node
    {
    public:
        Node *prev;
        int val;
        int key;
        Node *next;
        Node(int v, int k)
        {
            this->val = v;
            this->key = k;
        }
    };

    void addNode(Node *oldNode)
    {
        // adding node after head only
        Node *headNext = this->head->next;
        oldNode->next = headNext;
        oldNode->prev = this->head;
        headNext->prev = oldNode;
        this->head->next = oldNode;
        return;
    }

    void removeNode(Node *oldNode)
    {
        // removing current node connection to its neighbours
        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
        return;
    }
    Node *head = new Node(0, -1);
    Node *tail = new Node(0, -2);
    unordered_map<int, Node *> cache;

public:
    int cap;
    LRUCache(int capacity)
    {
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->cap = capacity;
        cache.clear();
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end()) // if not present return -1
            return -1;
        removeNode(cache[key]); // remove from previous location
        addNode(cache[key]);    // add it after head
        return cache[key]->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            removeNode(cache[key]);
            cache.erase(key);
        }
        if (cache.size() == this->cap)
        {
            // reomve last node before tail
            cache.erase(this->tail->prev->key);
            removeNode(this->tail->prev);
        }
        Node *node = new Node(value, key);
        addNode(node);
        cache[key] = node;
    }
};
int main()
{
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(3, 3);
    cache->put(2, 2765);
    cout << cache->get(1)<<endl;
    cout << cache->get(2)<<endl;
    return 0;
}