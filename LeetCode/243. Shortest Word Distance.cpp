/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
*/

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        if(words.size() < 2) return -1;
        int idx1 = -1;
        int idx2 = -1;
        int result = words.size();
        
        for(int i = 0; i<words.size();  i++) {
            
            if(words[i].compare(word1) == 0 )
            idx1 = i;
            
            if(words[i].compare(word2) == 0 )
            idx2 = i;
            
            if(idx1 != -1  &&  idx2 !=  -1)
            result = min(result, abs(idx1-idx2));
        }
        
        
        return  result;
        
    }
};
