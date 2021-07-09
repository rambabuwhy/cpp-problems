/*

Given a character array s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

Your code must solve the problem in-place, i.e. without allocating extra space.

 

Example 1:

Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Example 2:

Input: s = ["a"]
Output: ["a"]


*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        
        //reverse while world
        reverse(s.begin(),s.end());
        
        int start = 0;
        int end = 0;
        while(start < n) {
         
            //move 'end' before next word
            while(end < n && s[end] != ' ') end++;
            
            //reverse [start, end): include 'start' and not include 'end'
            reverse(s.begin()+start, s.begin()+end);  
            
            //move 'start' and 'end' to the begining of the next word
            end++;
            start = end;
        }
    }
};
