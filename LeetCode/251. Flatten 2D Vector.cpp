/*
Design and implement an iterator to flatten a 2d vector. It should support the following operations: next and hasNext.

 

Example:

Vector2D iterator = new Vector2D([[1,2],[3],[4]]);

iterator.next(); // return 1
iterator.next(); // return 2
iterator.next(); // return 3
iterator.hasNext(); // return true
iterator.hasNext(); // return true
iterator.next(); // return 4
iterator.hasNext(); // return false

*/

class Vector2D {
public:
    
    vector<vector<int>> lvec;
    int in =0;
    int out =0;
    
    Vector2D(vector<vector<int>>& v) {
        lvec = v;
    }
    
    int next() {
        if(!hasNext()) return -1;
        return lvec[out][in++];
    }
    
    bool hasNext() {
        
        //if you move from one vector to next.  'in' should be 0th element and 'out' shut be next vector
        while(out <lvec.size() && in == lvec[out].size()){
            in=0;
            out++;
        }
        return out < lvec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
