/*

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
*/

class Solution {
public:
    
    //push pushed items into stack and compare top element with popped one
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> l_stack;
        
        int i = 0;
        for(auto p:pushed){
            l_stack.push(p);
            while(!l_stack.empty() && l_stack.top() == popped[i] && i<pushed.size()) {
                l_stack.pop();
                i++;
            }
        }
        
        return i == pushed.size();
        
    }
};
