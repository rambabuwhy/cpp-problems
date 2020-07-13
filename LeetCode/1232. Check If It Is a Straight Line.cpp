class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int DY = coordinates[1][1] - coordinates[0][1];
	    int DX = coordinates[1][0] - coordinates[0][0];     
	    for( int i=2; i < coordinates.size(); i++ ) {
		    auto P = coordinates[i];
		    if( DX * (P[1] - coordinates[0][1]) != DY * (P[0] - coordinates[0][0]) )
			    return false;
	    }
	    return true;
        
    }
};
