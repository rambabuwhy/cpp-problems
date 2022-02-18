/*
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    //Given a sequence of digits [D1, D2, D3  ...Dn ], if the digit D2 is less than its left neighbor D1 , then we should remove the left neighbor (D 1) in order to obtain the minimum result.
    string removeKdigits(string num, int k) {
        string result = "";                                         // treat result as a stack in below for loop
       
       for (char c : num) {
           while (result.length() && result.back() > c && k) {
               result.pop_back();                                  // make sure digits in result are in ascending order
               k--;                                                // remove one char
           } 
           if (result.length() || c != '0') { result.push_back(c); }  // can't have leading '0'
       }
       
       while (result.length() && k--) { result.pop_back(); }          // make sure remove k digits in total
       
       return result.empty() ? "0" : result;
    }
};
