

/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Money Change Again 
 * Description: As we already know, a natural greedy strategy for the change problem 
 * does not work correctly for any set ofdenominations. For example, if the available
 * denominations are 1, 3, and 4, the greedy algorithm will change 6 cents using 
 * three coins (4 + 1 + 1) while it can be changed using just two coins (3 + 3). 
 * Your goal now is to apply dynamic programming for solving the Money Change Problem for denominations 1, 3, and 4.
 * */
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

long int get_change_recursive(vector<int> &coin, int m) {
  //write your code here
  if(m == 0 ) return 0;
  long int min_change = INT_MAX;
  for(int i = 0; i <  3; i++)
  {
    if(coin[i] <= m)
    {
      int  s = get_change_recursive(coin,m-coin[i]);
      if( s != INT_MAX &&  (s + 1) < min_change)
        min_change = s + 1;
    }
  }
  return min_change;
}

long int get_change_dp(vector<int> &coin, int m) {
  //write your code here
  //if(m == 0 ) return 0;
  long int table[m+1] ;
  table[0]= 0;
  for(int i=1;i <= m;i++)
  {
    table[i] = INT_MAX;
  }
  for(int i = 1; i <=  m; i++)
  {
    for(int j = 0; j <  coin.size(); j++)
    {
      if(coin[j] <= i)
      {
        int  s = table[i-coin[j]];
        if( s != INT_MAX &&  (s + 1) < table[i])
          table[i] = s + 1;
      }
    }
  }
  return table[m];
}
int main() {
  int m;
  std::cin >> m;
  vector<int> coin(3);
  coin[0]= 1;coin[1]=3;coin[2]=4;
  std::cout << get_change_dp(coin,m) << '\n';
}
