class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> M;
        for(auto c: s){
            M[c]++;
        }
        for(int i =0; i<s.length(); i++){
            if(M[s[i]] == 1){
                return i;
            }
        }
        return -1;
        
    }
};
