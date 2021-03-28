/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
Example 1:
Input: "owoztneoer"

Output: "012"
Example 2:
Input: "fviefuro"

Output: "45"

*/


class Solution {
public:
    string originalDigits(string s) {
        
        //letter -> frequency
        vector<int> alpha(128, 0);
        for (char c : s){
            alpha[c]++;
        }
        
        //digit -> frequency
        vector<int> a(10, 0);
        a[0] = alpha['z'];
        a[2] = alpha['w'];
        a[4] = alpha['u'];
        a[6] = alpha['x'];
        a[8] = alpha['g'];
        a[3] = alpha['h'] - a[8];
        a[5] = alpha['f'] - a[4];
        a[7] = alpha['v'] - a[5];
        a[1] = alpha['o'] - a[0] - a[2] - a[4];
        a[9] = alpha['i'] - a[5] - a[6] - a[8];
        
        //output
        string ans;
        for (int i = 0; i < 10; i++) {
            if (a[i] > 0)
                ans += string(a[i], '0' + i);
        }
        return ans;
    }
};
