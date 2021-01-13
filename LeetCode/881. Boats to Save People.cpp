/*

The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)


*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        if(people.size() <2) return 0;
        
        sort(people.begin(),  people.end());
        
        //two pointer method
        int start = 0;
        int end = people.size()-1;
        
        int count = 0;
        while( start <= end){
           
            if(people[start] + people[end] <= limit)
            start++;
            
            //else
            //else not required.  
            //if it is more than limit we will consider end as single travellor
            end--;
            
            count++;
        }
        
        return count;
        
    }
};
