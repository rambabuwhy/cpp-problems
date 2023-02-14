/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Find All Anagrams in a String

------------------------------------------------------------------
Description:
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
--------------------------------------------------------------------------------------------------------
Solution:
The function uses two arrays, target and window, to store the frequency of each character in p and the current window in s, respectively. 
The target array is initialized with the frequency of each character in p, and the window array is initialized with the frequency of the first n characters in s, 
where n is the length of p. The function then moves the window one character to the right at a time, updating the frequency of characters in the window as it goes. 
If the target and window arrays are equal, it adds the starting index of the window to the result vector. Finally, the function returns the result vector.
*/

#include <vector>
#include <string>

using namespace std;

// Function to find all the start indices of anagrams of string p in string s
vector<int> findAnagrams(string s, string p) {
    // Initialize the result vector
    vector<int> res;

    // Return an empty vector if s is empty or if s is shorter than p
    if (s.empty() || p.empty() || s.size() < p.size()) return res;

    // Get the lengths of s and p
    int m = s.size(), n = p.size();

    // Initialize two arrays, target and window, to store the frequency of each character
    vector<int> target(26, 0), window(26, 0);

    // Store the frequency of each character in p in the target array
    for (int i = 0; i < n; i++) {
        target[p[i] - 'a']++;
        window[s[i] - 'a']++;
    }

    // If the window and target arrays are equal, add the starting index of the window to the result vector
    if (target == window) res.push_back(0);

    // Move the window to the right one character at a time
    for (int i = n; i < m; i++) {
        // Decrement the frequency of the character that is leaving the window
        window[s[i - n] - 'a']--;
        // Increment the frequency of the character that is entering the window
        window[s[i] - 'a']++;
        // If the window and target arrays are equal, add the starting index of the window to the result vector
        if (target == window) res.push_back(i - n + 1);
    }

    // Return the result vector
    return res;
}

int main() {
    string s = "cbaebabacd", p = "abc";
    vector<int> res = findAnagrams(s, p);
    for (int i : res) cout << i << " ";
    return 0;
}
