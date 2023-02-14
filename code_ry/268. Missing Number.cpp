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
With these properties in mind, let's consider the input array [9, 6, 4, 2, 3, 5, 7, 0, 1] and the expected output of 8.

We know that the array contains n distinct numbers in the range [0, n], which means that the array should contain all numbers from 0 to n, except for one missing number.

The XOR solution takes advantage of this fact by using the XOR operation to "cancel out" all the numbers in the array, except for the missing number. Here's how it works:

Initialize "missing" variable to n, the last number in the range:

int missing = nums.size();

Iterate over the array, and for each index i and corresponding element nums[i], perform the following XOR operation:

missing = missing ^ i ^ nums[i];

This operation cancels out the value at the ith index, as well as the index itself, leaving behind only the missing number.

For example, let's consider the first iteration where i=0 and nums[0]=9:

missing = missing ^ i ^ nums[i]
= 9 ^ 0 ^ 9
= 0

We can see that the XOR operation has cancelled out the value 9 at index 0, leaving behind only the missing number 8.

Once the iteration is complete, the missing number will be stored in the "missing" variable. In this case, we would return 8.

I hope that explanation helps you understand the logic behind the XOR solution! Let me know if you have any further questions.
------------------------------------------------------------------
*/
int missingNumber(vector<int>& nums) {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        missing ^= i ^ nums[i];
    }
    return missing;
}
