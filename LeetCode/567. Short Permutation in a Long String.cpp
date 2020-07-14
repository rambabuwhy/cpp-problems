class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return false;
        
        vector<int> vs1(26,0);
        vector<int> vs2(26,0);
        
        for(int i = 0 ; i <s1.size(); i++){
            vs1[s1[i]-'a']++;
        }
        
        for(int i = 0; i< s2.size(); i++) {
            
            vs2[s2[i]-'a']++;
            
            if(i > s1.size()-1) {
                vs2[s2[i-s1.size()]-'a']--;
                
            }
            
            if(vs1 == vs2) return  true;
        }
        return false;
        
    }
};
