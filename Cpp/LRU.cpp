#include <iostream>
#include <unordered_map>
#include <list>
#include <mutex>

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        std::
        <std::mutex> lock(m);
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        std::unique_lock<std::mutex> lock(m);
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }

private:
    typedef std::list<int> LI;
    typedef std::pair<int, LI::iterator> PII;
    typedef std::unordered_map<int, PII> HIPII;

    HIPII cache;
    LI used;
    std::mutex m;
    int _capacity;

    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};
