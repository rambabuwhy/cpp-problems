

/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Longest Common Subsequence of Two Sequences 
 * Description:Compute the length of a longest common subsequence of three sequences.
 * */


#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int table[a.size()+1][b.size()+1];
  for(int i = 0 ;i <= a.size(); i++)
  {
    for(int j = 0 ; j <= b.size(); j++)
    {
      if(i==0 || j==0) table[i][j]=0;
      else if(a[i-1] == b[j-1])
        table[i][j]= 1 + table[i-1][j-1];
      else
        table[i][j]= max(table[i][j-1],table[i-1][j]);
    }
  }
  return table[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
