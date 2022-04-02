/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

class Solution {
public:
    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;        
        while (i < j) {
            
            if (s[i] != s[j]) {
                // mismatch: try both deletions
                return (checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j));
            }            
            i++;
            j--;
        }        
        return true;
    }    
    
    bool checkPalindrome(string s, int i, int j) {
        while (i < j) {
            
            if (s[i] != s[j]) {
                return false;
            }            
            i++;
            j--;
        }        
        return true;
    }   

};
