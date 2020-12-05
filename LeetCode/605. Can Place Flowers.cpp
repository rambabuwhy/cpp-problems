/*

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        int i = 0;
    
        while( i < flowerbed.size()) {
        
            //three conditions 


            bool c1 =  flowerbed[i] == 0 ;                        //  1.  It should be 0
            bool c2 =  (i == 0 || flowerbed[i-1] == 0) ;          // 2.  previous position should be 0
            bool c3 =  (i ==flowerbed.size()-1 || flowerbed[i+1] == 0 ); //3.next position should be 0

            if (c1 && c2 && c3) {

                flowerbed[i] = 1;
                count = count +1;
            }
        
            i = i + 1;
        }
    
        return count >= n;
    
        
    }
};
