/*
Given two words beginWord and endWord, and a dictionary wordList, return the length of the shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Return 0 if there is no such transformation sequence.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> uset(wordList.begin(), wordList.end());
        queue<string> Q;
        Q.push(beginWord);
        int count = 1;
        
        while(!Q.empty()){
            
            int size = Q.size();
            
            for(int i =0; i<size; i++){
                
                string cword = Q.front();
                Q.pop();
   
                if(cword ==endWord)
                return count;
                
                for(int j =0; j<cword.size(); j++){
                    
                    char temp = cword[j];
                    for(int k =0; k<26; k++){
                        
                        cword[j] = 'a' + k;
                        
                        if(uset.find(cword) != uset.end())
                        Q.push(cword),uset.erase(cword);
                        
                    }
                    cword[j] = temp;
                }
             
            }
            count++;
        }
        
        
        return 0;
        
    }
};
