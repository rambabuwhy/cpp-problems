/*

We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        //bring all  evens in 0th position:  cost 0 ->alternative i-2
        //bring all  odds in 1th  position:  cost 0 -> alternative i-2
        //bring 0th to 1st  or  1st to 0th  :  cost 1
        //minimum of it(0th to 1st  ,  1st to 0th)
        int even=0,odd=0;
        for(int i =0;i<position.size();i++){
            if(position[i]%2==0) even++;
            else odd++;
            
        }
        return min(even,odd);
        
    }
};
