#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
	int i=0, j=array.size()-1;
	while( i<j ){
		
		//move until j != 2
		while(i<j && array[j] == toMove) j--;
		
		//here j != 2 ; swap i with j 
		if(array[i] == toMove) swap(array[i], array[j]);
		
		i++;
		
	}
  return array;
}
