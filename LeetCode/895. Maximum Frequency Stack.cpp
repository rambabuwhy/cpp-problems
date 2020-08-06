/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.

*/

class FreqStack {
public:
    FreqStack() {
        maxFreq=0;
        
    }
    
    void push(int x) {

        int f = ++freq[x];
        maxFreq = max(maxFreq,f);
        mstack[f].push(x);
    
    }
    
    int pop() {
        
        int x = mstack[maxFreq].top();
        mstack[maxFreq].pop();
        
        int f = freq[x]--;
        if(mstack[f].size() == 0){
            maxFreq--;
        }      
      
        return x;
    }
    
private:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> mstack;
    int maxFreq;
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
