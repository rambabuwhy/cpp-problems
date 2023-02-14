/*

Author: Rambabu Yerajana
linkedin: https://www.linkedin.com/in/rambabuyerajana/
problem: Add Binary
------------------------------------------------------------------
Problem:
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
----------------------------------------------------------------------
Solution:
The idea is to iterate through both strings from their rightmost digits and perform a binary addition, keeping track of the carry. 
The sum and carry are computed using integer arithmetic and added to the result string. Finally, the result is reversed and returned.
--------------------------------------------------------------------
The time complexity of this solution is O(max(N, M)), where N and M are the lengths of the input strings a and b, respectively. This is because the algorithm iterates through both strings only once, performing a constant amount of work per digit.

The space complexity of this solution is also O(max(N, M)), which is the space needed to store the output string. Note that we are not using any extra data structures to store intermediate results, which makes this solution space-efficient.

Therefore, this solution is both time and space optimized for the problem of adding two binary strings.
*/



string addBinary(string a, string b) {
    // Initialize variables
    int carry = 0, i = a.size()-1, j = b.size()-1;
    string res = "";

    // Iterate through both strings from right to left
    while (i >= 0 || j >= 0 || carry) {
        // Compute sum of digits at the current position, plus any carry
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // Subtract '0' to convert char to int
        if (j >= 0) sum += b[j--] - '0'; // Subtract '0' to convert char to int

        // Append the least significant bit of the sum to the result string
        res += to_string(sum % 2);

        // Compute the carry for the next iteration
        carry = sum / 2;
    }

    // Reverse the result string and return it
    reverse(res.begin(), res.end());
    return res;
}
