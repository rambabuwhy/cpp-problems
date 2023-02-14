/*

Author: Rambabu Yerajana
linkedin: https://www.linkedin.com/in/rambabuyerajana/
problem: Rotate String
------------------------------------------------------------------
Problem:
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
------------------------------------------------------
Solution:
This program is a solution to determine if a string s can become another string goal after some number of shifts.

The function canBecome takes two strings as input and returns a boolean value indicating whether the first string s can become the second string goal after some number of shifts.

The function first checks if the lengths of the two strings are equal, and if not, it returns false. If the lengths are equal, the function enters a loop that iterates n times, where n is the length of the string s.

In each iteration of the loop, the function uses the substr function to create a new string that consists of a combination of two substrings of s:

The first substring starts from the ith character of s and goes to the end of s.
The second substring starts from the beginning of s and goes to the i - 1th character of s.
The function then compares this new string to goal and if they are equal, it returns true.

The loop continues until either the strings are found to be equal or the loop has iterated n times. If the loop finishes and no match has been found, the function returns false.
----------------------------------------------
This solution is not optimized in terms of time complexity, as it takes O(n^2) time in the worst case, where n is the length of the input string s. This is because the substr function takes O(n) time and it is called n times in the loop.

If you need a more optimized solution, you can use the KMP (Knuth-Morris-Pratt) algorithm to solve this problem in O(n) time. However, this requires a deeper understanding of string algorithms and may not be suitable for all audiences.

*/


#include <string>

bool canBecome(std::string s, std::string goal) {
    if (s.length() != goal.length()) return false;

    for (int i = 0; i < s.length(); ++i) {
        if (s.substr(i) + s.substr(0, i) == goal) return true;
    }

    return false;
}
