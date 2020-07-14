class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        //base case
        if(s.size() < p.size()) return vector<int>();
        
        //result vector
        vector<int> result;
        
        //count for p  vector
        vector<int> vp(26,0);
        
        //count for s  vector
        vector<int> vs(26,0);
        
        //count p chars
        for(int i=0; i<p.size(); i++){
            vp[p[i]-'a']++;
        }
        
        //iterate s  and compare p
        for(int i=0; i<s.size(); i++){
            
            vs[s[i]-'a']++;
            if(i > p.size()-1) {
                vs[s[i-p.size()]-'a']--;
            }
        
            if(vp == vs ) result.push_back(i-p.size()+1);
            
        }
        return result;
    }
};
