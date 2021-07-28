/*

Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Example 2:

Input: s = " "
Output: 0

*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        //last char of last word
        int last = s.size()-1;
        
        while(last >= 0 && s[last] == ' ') last--;
        
        //first char of last word
        int first = 0;
        while(last >= 0 && s[last] != ' ') last--, first++;
        
        return first;        
    }
};
