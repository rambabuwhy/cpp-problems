

/*
 * Author: Rambabu Yerajana
 * Text:   CrackingTheCodinglnterview 
 * Topic:  Puzzle 
 * Statement: Triple_Step 
 * Description:A child is running up a staircase with n steps and can hop
 * either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the
 * child can run up the stairs. 
 * */

#include <iostream>
using namespace std;
int triple_step(int n)
{
  if(n<0)return 0;
  if(n==0)return 1;
  return ( triple_step(n-1) + triple_step(n-2) + triple_step(n-3));
}
int main()
{
  int n;
  cout << "Enter N:";
  cin >> n;
  cout<< "\n Ans: "<< triple_step(n) << endl;
  return 0;
}
