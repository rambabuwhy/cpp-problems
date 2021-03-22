/*

Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period '.' refers to the current directory. Furthermore, a double period '..' moves the directory up a level.

Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names. The last directory name (if it exists) must not end with a trailing '/'. Also, the canonical path must be the shortest string representing the absolute path.

*/

class Solution {
public:
    string simplifyPath(string path) {
        
        if(path.empty()) return path;
        
        stack<string> S;
        istringstream ss(path);
        
        string cs;
        
        //step 1: get string by string with delimiter '\':  then  push valid string into stack
        while(getline(ss,cs,'/')){
            
            //if it is '.' :then dont do any thing : get next string 
            if(!cs.empty() && cs == "."){
                continue;
            }
            
            //if it is ".." : then remove top from stach and get next string
            if(cs == ".."){
                if(!S.empty()){
                    S.pop();
                }
                continue;
            }
            
            //if other than '.' & '..'   then push into stack
            if(!cs.empty()){
                S.push(cs);
            }
           
        }
        
        //step 2: create new string from stack
        string result;
        while(!S.empty()){
            result =  "/" + S.top() + result;
            S.pop(); 
        }
        
        return result.empty()? "/" :result; 
    }
};
