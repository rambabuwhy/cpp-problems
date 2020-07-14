/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

*/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(   begin(costs), 
                end(costs),
                [](const vector<int> &p, const vector<int> &q) {
                     return (p[0] - p[1] < q[0] - q[1]);
                }
            );
        int min = 0;
        int n = costs.size() / 2;
    
        for (int i = 0; i < n; ++i) {
            min += costs[i][0] + costs[i + n][1];
        }
        return min;
        
    }
};
