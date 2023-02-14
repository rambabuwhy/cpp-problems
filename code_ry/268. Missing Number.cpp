/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Missing Number

------------------------------------------------------------------

Description:
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.


------------------------------------------------------------------

Solution:
First, initialize a variable "missing" to n, which represents the number that is missing from the array.
Then, iterate through the array and perform XOR between the index and the value at that index. Finally, perform XOR between the result and the "missing" variable.

At the end of the iteration, the "missing" variable will contain the missing number in the range [0, n].

------------------------------------------------------------------

Notes:

Note that this solution has a time complexity of O(n) and a space complexity of O(1).
The key insight behind this solution is that the XOR operation is both commutative (order of operands does not matter) and associative (grouping of operands does not matter), which means that:

a ^ b = b ^ a (commutativity)
a ^ b ^ c = a ^ (b ^ c) = (a ^ b) ^ c (associativity)

Suppose we have an array nums containing n distinct numbers in the range [0, n], except for one number which is missing. The goal is to find the missing number.

One way to do this is to calculate the sum of all the numbers in the range [0, n], and then subtract the sum of the numbers in the array. 
The difference between the two sums will be the missing number. However, this approach requires us to iterate over the entire array twice, 
which has a time complexity of O(n).

A more efficient solution is to use the XOR operator. The XOR operator has the property that a ^ a = 0 for any number a, and a ^ 0 = a for any number a. 
This means that if we XOR all the numbers in the range [0, n] together, and then XOR all the numbers in the array together, 
the result of the two XOR operations will be the missing number.

To implement this solution in C++, we can initialize a variable missing to nums.size(), which is one greater than the maximum possible value in the array. 
We then iterate over the elements in the array and perform an XOR operation between the index i and the element nums[i]. 
The result of this XOR operation is then XORed with missing. The goal is to cancel out all of the elements in the array, leaving behind only the missing number.
------------------------------------------------------------------
*/
int missingNumber(vector<int>& nums) {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}
