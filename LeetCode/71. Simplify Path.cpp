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
        
        while(getline(ss,cs,'/')){
            
            if(!cs.empty() && cs == "."){
                continue;
            }
            
            if(cs == ".."){
                if(!S.empty()){
                    S.pop();
                }
                
                continue;
            }
            
           
            if(!cs.empty())
            S.push(cs);
        
        }
        
       
        string result;
        while(!S.empty()){
            result =  "/" + S.top() + result;
            S.pop();
            
           
        }
        
        return result.empty()?"/":result;
        
    }
};
