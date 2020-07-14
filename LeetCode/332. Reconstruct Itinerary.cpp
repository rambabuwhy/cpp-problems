/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.

*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
         
        unordered_map<string, multiset<string>> m;
        for (auto ticket : tickets) {
            m[ticket[0]].insert(ticket[1]);
        }
        vector<string> march = { "JFK" }; 
        vector<string> results; 
        while (march.empty() == false) {
            string & from = march.back();
            if ((m.find(from) != m.end()) && (m[from].empty() == false)) { 
                multiset<string> & to = m[from];
                march.push_back(*(to.begin()));
                to.erase(to.begin());
            } else { 
                results.push_back(march.back()); 
                march.pop_back();
            }
        }
        reverse(results.begin(), results.end()); 
        return results;
        
    }
};
