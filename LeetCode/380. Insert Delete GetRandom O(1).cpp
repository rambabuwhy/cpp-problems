/*
Design a data structure that supports all following operations in average O(1) time.

 

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned
*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, int>::iterator it = indices.find(val);
        if (it == indices.end())   {
           indices.insert(pair<int, int>(val, vals.size()));
            vals.push_back(val);
            
            return true;
        }
        return false;  
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator it = indices.find(val);
        if (it == indices.end())   {
            return false;
        }
        int index = it->second;
        vals[index] = vals[vals.size() - 1];
        indices.find(vals[index])->second = index;
        vals.pop_back();
        indices.erase(it);
        return true; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vals[rand() % vals.size()];
        
    }
private:
    unordered_map<int, int> indices; 
    vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
