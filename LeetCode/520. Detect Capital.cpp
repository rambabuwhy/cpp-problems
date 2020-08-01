/*

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        
       // is allcaps = false;
        int allcaps = 0;
        for(int i =0; i<word.size();i++){
            
            if(isupper(word[i])) {

                allcaps++;
                
            }
       
        }
        
        if(allcaps == word.size() || allcaps ==0 )  return true;
        if(allcaps == 1 && isupper(word[0]))  return true;
            
        return false;
        
    }
};
