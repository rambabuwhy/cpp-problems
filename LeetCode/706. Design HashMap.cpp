/*
Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 

*/

class MyHashMap {
    
    vector<list<pair<int,int>>> hmap;
    size_t hmap_size = 10000;
public:
    
    // Initialize 
    MyHashMap() {
        hmap.resize(hmap_size);
    }
    
    //put
    void put(int key, int value) {
        auto &list = hmap[key % hmap_size];
        for (auto & val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }
    
    //get
    int get(int key) {
        const auto &list = hmap[key % hmap_size];
        if (list.empty()) {
            return -1;
        }
        for (const auto & val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }
    
    //remove
    void remove(int key) {
        auto &list = hmap[key % hmap_size];
        list.remove_if([key](auto n) { return n.first == key; });
    }
};
