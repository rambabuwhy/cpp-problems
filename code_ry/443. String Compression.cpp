/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: String Compression

------------------------------------------------------------------

Description:

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

------------------------------------------------------------------

Solution:

The idea behind the solution is to maintain two pointers i and j on the input array chars. 
The pointer i is used to iterate through the array, and the pointer j is used to store the compressed string.

For each group of consecutive repeating characters in chars, we count the number of repeating characters and append the character followed by the group's length to the compressed string chars[j]. 
If the group's length is 1, we just append the character itself. We use the to_string function to convert the group length to a string and iterate through each character of the string, appending it to the compressed string.

Finally, we return the length of the compressed string, which is stored in j.

Since the solution only uses two pointers to traverse the input array and does not use any additional data structures or built-in functions, it satisfies the constant extra space requirement.
------------------------------------------------------------------

Notes:
The time complexity of this algorithm is O(n), where n is the length of the input array. We iterate through the array only once to count the number of consecutive repeating characters and append the compressed string to the output array.

------------------------------------------------------------------
*/

int compress(vector<char>& chars) {
    // Initialize two pointers: i for iterating through the array, and j for storing the compressed string
    int i = 0, j = 0, n = chars.size();
    
    // Loop through the array
    while (i < n) {
        // Count the number of consecutive repeating characters
        int count = 0;
        char c = chars[i];
        while (i < n && chars[i] == c) {
            ++i;
            ++count;
        }
        
        // Append the compressed string to chars[j]
        chars[j++] = c;
        if (count == 1) continue; // If there is only one repeating character, skip appending the count
        for (char ch : to_string(count)) { // Convert the count to a string and append each character to chars[j]
            chars[j++] = ch;
        }
    }
    
    // Return the length of the compressed string
    return j;
}

