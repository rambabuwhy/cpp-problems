/*
Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.

Return the power of the string.
*/
class Solution {
public:
    int maxPower(string s) {
        
        int count = 0;
        int maxCount = 0;
        char prev = ' ';
        for(int i = 0;i<s.size();i++){
            if(prev == s[i]){
                count++;
                
            }
            else{
                count = 1;
                prev = s[i];
            }
            
            maxCount = max(count,maxCount);
        }
        return  maxCount;
        
    }
};
