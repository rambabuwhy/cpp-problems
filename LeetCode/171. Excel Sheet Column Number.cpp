/*
For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701

*/

class Solution {
public:
    int titleToNumber(string s) {
        
        //Logic: same as base 10 ;  this is base 26;  just add as logic of base 10
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
             result = result * 26 + (s[i] -'A') + 1;
        }
        
        return  result;
        
    }
};
