/*
problem:
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
---------------------------------------------------
Solution:
The algorithm uses a sliding window approach where the start and end indices keep moving to the right while maintaining the two types of fruits in the baskets and their counts in a hash map.
When the size of the hash map exceeds 2, it means that there is a third type of fruit, so we have to remove the fruits from the left side of the window until there are only two types of fruits in the baskets.
We keep updating the maxFruits value with the maximum size of the window.
---------------------------------------------------
The time complexity of the algorithm is O(n) because each fruit is processed only once. The unordered_map data structure allows for constant time lookups, inserts, and deletes, making the overall time complexity linear. This algorithm is more efficient than a brute force approach, which would have a time complexity of O(n^2)
*/

#include <iostream>
#include <unordered_map>

// Function to calculate the maximum number of fruits that can be picked
int totalFruit(vector<int>& fruits) {
    int start = 0, end = 0, maxFruits = 0;
    unordered_map<int, int> basket;  // Hash map to store the fruit types and their counts

    // Start from the left and move to the right
    while (end < fruits.size()) {
        basket[fruits[end]]++;  // Add the fruit to the basket
        // If there are more than 2 types of fruits in the basket, remove the fruit from the left side of the window
        while (basket.size() > 2) {
            basket[fruits[start]]--;  // Remove the fruit from the basket
            if (basket[fruits[start]] == 0) {  // If the count of the fruit becomes 0, remove it from the hash map
                basket.erase(fruits[start]);
            }
            start++;  // Move the start of the window to the right
        }
        // Update the maximum number of fruits that can be picked
        maxFruits = max(maxFruits, end - start + 1);
        end++;  // Move the end of the window to the right
    }
    return maxFruits;
}
