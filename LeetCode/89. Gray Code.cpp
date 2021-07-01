/*
An n-bit gray code sequence is a sequence of 2n integers where:

Every integer is in the inclusive range [0, 2n - 1],
The first integer is 0,
An integer appears no more than once in the sequence,
The binary representation of every pair of adjacent integers differs by exactly one bit, and
The binary representation of the first and last integers differs by exactly one bit.
Given an integer n, return any valid n-bit gray code sequence.

 

Example 1:

Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
Example 2:

Input: n = 1
Output: [0,1]
*/


class Solution {
public:
    vector<int> grayCode(int n) {
        
        //store result
        vector<int> result;
        
        //store visited one to verify if already present 
        unordered_set<int> visit;
        
        //gray code start with zero
        result.push_back(0);
        visit.insert(0);
        grayCodeHelper(result, n, visit);
        return result;
    }

private :
    bool grayCodeHelper(vector<int> &result, int n, unordered_set<int> &visit) {
        
        //max numbers pow(2, n)  or 1 << n
        if (result.size() == (1 << n)) return true;

        //take last digit and toggle every digit; verify if already present
        int current = result[result.size() - 1];
        for (int i = 0; i < n; i++) {
            
            //toggle every bit
            int next = current ^ (1 << i);
            
            //verify if already present
            if (visit.find(next) == visit.end()) {
                visit.insert(next);
                result.push_back(next);
                
                if (grayCodeHelper(result, n, visit)) {
                    return true;
                }
                
                // If no valid sequence found delete the last added number and continue the search.
                visit.erase(next);
                result.pop_back();
            }
        }
        return false;
    }
};
