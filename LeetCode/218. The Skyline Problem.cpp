/*

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

 
 
 
 */
 
 class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> edges;
        int left, right, height;
        
        for(int i=0; i<buildings.size(); i++){
            left=buildings[i][0];
            right=buildings[i][1];
            height=buildings[i][2];
            
            // start-height add -ve to identify start-height
            edges.push_back(make_pair(left, -height));
            
            //end-height
            edges.push_back(make_pair(right, height));
        }
        
        sort(edges.begin(), edges.end());
        
        vector<vector<int>> result;
        /*use the multiset to store the max height util current pos */
        multiset<int> m;
        
        /*left most height */
        m.insert(0);
        int prev=0, curr=0;
        for(int i=0; i<edges.size(); i++){
            
            pair<int, int> e=edges[i];
            
            //if it is  start-height insert into set m
            if(e.second < 0)  m.insert(-e.second);
            
            //if it is end-heoght  remove from set m
            else m.erase(m.find(e.second));
            
            //insert into result:  before check height changes
            curr=*(m.rbegin());
            if(curr!=prev){
                result.push_back({e.first, curr});
                prev=curr;
            }
        }
        return result;
        
    }
};
