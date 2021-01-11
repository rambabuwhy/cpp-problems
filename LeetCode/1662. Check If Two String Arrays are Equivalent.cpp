class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s1;
        string s2;
        
        for(string s:word1){
            s1.append(s);
        }
        
        for(string s:word2){
            s2.append(s);
        }
       
        if(s1==s2) return true;
        else return false;

    }
};
