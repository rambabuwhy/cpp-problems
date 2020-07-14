class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<int> nextCell(8);
        vector<vector<int>> table;
        while (N--) {
            for (int i = 1; i < 7; i++) {
                nextCell[i] = cells[i - 1] == cells[i + 1];
            }
            if (table.size() && table.front() == nextCell) return table[N % table.size()]; 
            else table.push_back(nextCell);
            cells = nextCell;
        }
        return cells;
        
    }
};
