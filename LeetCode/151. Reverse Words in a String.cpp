/*

Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

*/
class Solution {
public:
    string reverseWords(string s) {
        
        //step1: reverse whole string
        reverse(s.begin(),s.end());
        
        //Step2: reverse word by word
        
        int index = 0;
        for(int start=0; start<s.size(); start++){
            if(s[start] != ' '){
                
                //step2.1:  find begning of the word
                if( index != 0) s[index++]=' ';
               
                //step2.2  find end of the word
                int end=start;
                while(end<s.size() && s[end] != ' '){
                    s[index++]=s[end++];
                }
                
                //step 2.3: reverse word from beging to end
                reverse(s.begin()+index-(end-start),s.begin()+index);
                
                
                //to next word
                start = end;
            
            }
         
        }
        s.erase(s.begin() + index, s.end());
        
        return s;
        
    }
};
