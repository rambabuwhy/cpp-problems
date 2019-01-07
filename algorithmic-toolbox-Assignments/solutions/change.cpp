
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Money Change
 * Description: In this problem, you will design and implement an elementary
 * greedy algorithm used by cashiers all over the world millions of times per day.
 * The goal in this problem is to find the minimum number of coins needed to
 * change the input value (an integer) into coins with denominations 1, 5, and 10.
 * */

#include <iostream>

long long get_change(long long m) {
  //write your code here
  long long total=0;
  if(m >= 10)
  {
    total =  total + m /  10;
    m = m % 10;
  }
  if(m >= 5 )
  {
    total = total + m / 5;
    m = m % 5;
  }
  total = total + m;
  return total;
}

int main() {
  long long  m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
