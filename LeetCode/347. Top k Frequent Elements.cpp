/*

Given a non-empty array of integers, return the k most frequent elements.

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //map for num ->  frequency
        unordered_map<int, int> Map;
        
        //priority queue  to maintain top frequest elements
        priority_queue<int, vector<int>, greater<int>> pq;
        
        //count and insert into  map
        for(auto i : nums) ++Map[i];
        
        //insert into pri queue
        for(auto & i : Map) {
            pq.push(i.second);
            while(pq.size() > k) pq.pop();
        }
        
        //insert into  result vector
        vector<int> result;
        for(auto & itr : Map) {
            if(itr.second >= pq.top()) result.push_back(itr.first);
        }
        return result;
        
    }
};
