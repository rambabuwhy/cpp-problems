class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.empty() && magazine.empty()) return true;
        if(magazine.empty()) return false;
        
        unordered_multiset<char> mag;
        for(auto c:magazine){
            mag.emplace(c);
            
        }
        for(auto c:ransomNote){
            unordered_multiset<char> ::iterator itr = mag.find(c);
            if(itr == mag.end()){
                return false;
            }
            mag.erase(itr);
        }
        return true;
        
    }
};
