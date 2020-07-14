/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.empty()) return;
        if(s.size() == 1) return;
        for(int i=0;i<s.size()/2;i++){
            
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i]=temp;
       
        }
        
    }
};
