class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        if(J.length() <= 0 || S.length() <=0) return 0;
        set<char> _s(J.begin(),J.end());
        int result = 0;
        for(auto c:J){
            _s.emplace(c);
        }
        for(auto c:S){
            if(_s.find(c) != _s.end()){
                result++;
            }
        }
        
        
        return result;
        
        
    }
};
