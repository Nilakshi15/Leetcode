class LRUCache {
private:
    int cap;

    // Doubly linked list: each element stores (key, value)
    list<pair<int,int>> cacheList;

    // Map from key -> iterator into the list
    unordered_map<int, list<pair<int,int>>::iterator> cacheMap;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);

        if (it == cacheMap.end()) {
            return -1;
        }

        // Move the accessed node to the front (most recently used)
        cacheList.splice(cacheList.begin(), cacheList, it->second);

        // Update map to new iterator position
        cacheMap[key] = cacheList.begin();
        return cacheList.begin()->second;

    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);

        if (it != cacheMap.end()) {
            // Key exists: update value and move to front
            it->second->second = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            cacheMap[key] = cacheList.begin();
        } else {

            // Key does NOT exist, check capacity
            if ((int)cacheList.size() == cap) {

                // Remove least recently used item (back of list)
                auto last = cacheList.back();
                int lastKey = last.first;
                cacheMap.erase(lastKey);
                cacheList.pop_back();
            }
            
            // Insert new key/value at front
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */