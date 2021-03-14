/*

Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

Example 1:

Input: num = "69"
Output: true
Example 2:

Input: num = "88"
Output: true
Example 3:

Input: num = "962"
Output: false
Example 4:

Input: num = "1"
Output: true

*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        
        unordered_map<char, char> lmap = {{'0','0'},
                                          {'1','1'},
                                          {'6','9'},
                                          {'8','8'},
                                          {'9','6'}};
        
        int left_index = 0;
        int right_index = num.size()-1;
        
        while( left_index <= right_index){
            
            char left_char = num[left_index];
            char right_char = num[right_index];
            
            if(lmap.find(left_char) == lmap.end()){
                return false;
            }
            
            if(lmap[left_char] != right_char){
                return false;
            }
            
            left_index++;
            right_index--;
            
        }
        return true;
    }
};
