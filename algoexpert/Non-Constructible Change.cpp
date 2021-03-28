#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
	
	int result = 0;
	sort(coins.begin(), coins.end());
	
	for(int i=0; i<coins.size(); i++){
		if(result+1 < coins[i]) return result+1;
		
		result = result+ coins[i];
	}
  return result + 1;
}
