/*

Given an array w of positive integers, where w[i] describes the weight of index i(0-indexed), write a function pickIndex which randomly picks an index in proportion to its weight.

For example, given an input list of values w = [2, 8], when we pick up a number out of it, the chance is that 8 times out of 10 we should pick the number 1 as the answer since it's the second element of the array (w[1] = 8).


*/

class Solution {
    vector<int> Psum;
public:
    Solution(vector<int>& w) {
        
        for(auto i:w){
            if(Psum.empty()){
                Psum.push_back(i);
                continue;
            }
            Psum.push_back(i + Psum.back() );
        }
        
        
        for(int i = 0 ; i<Psum.size();i++){ 
            cout<<Psum[i]<<" ";
           
        }
         cout<<endl;
    }
    
    int pickIndex() {
        auto T = rand() % Psum.back();
        cout<<"T:"<<T<<endl;
        return upper_bound(begin(Psum), end(Psum), T) - begin(Psum);
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
