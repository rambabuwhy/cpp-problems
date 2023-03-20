/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Can Place Flowers
------------------------------------------------------------------
Description:
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


------------------------------------------------------------------
Solution:
The idea is to iterate through the flowerbed array and for each empty plot, check if its adjacent plots are also empty. 
If so, we plant a flower in that plot and increment the count of planted flowers. Once the count reaches the target number of new flowers to be planted (n), we can stop iterating and return true. 
If we finish iterating through the whole array without being able to plant n new flowers, we return false.


------------------------------------------------------------------
Notes:


------------------------------------------------------------------
*/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        for(int i=0; i < flowerbed.size();i ++) {
        
            //if we want plant , current, prevous and next plots should be empty
            bool c1 =  flowerbed[i] == 0 ; //  1.  current plot shoud be empty (0)
            bool c2 =  (i == 0 || flowerbed[i-1] == 0) ; // 2.  previous plot should be empty(0)
            bool c3 =  (i ==flowerbed.size()-1 || flowerbed[i+1] == 0 ); //3.next plot should be empty(0)

            if (c1 && c2 && c3) { // if all three slots are empty then we can plant
                flowerbed[i] = 1;
                count = count +1;
            }
        }
        return count >= n; 
    }
};
