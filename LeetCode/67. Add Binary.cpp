/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int F = (i >= 0 && a[i] == '1');
            int S = (j >= 0 && b[j] == '1');
            result = to_string((F + S + carry) & 0x1) + result;
            carry = (F + S + carry) >> 1;
        }
        return carry ? '1' + result : result;         
        
    }
};
