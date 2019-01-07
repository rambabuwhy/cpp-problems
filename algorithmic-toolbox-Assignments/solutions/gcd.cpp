
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Greatest Common Divisor
 * Description:The greatest common divisor GCD(𝑎, 𝑏) of two non-negative integers 𝑎 and 𝑏
 * (which are not both equal to 0) is the greatest integer 𝑑 that divides both 𝑎 and 𝑏. 
 * Your goal in this problem is to 
 * */

#include <iostream>
using namespace std;
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  if(a==0) return b;
  if(b==0) return a;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long  a, long long b) {
  if(b == 0) return a;
  else if ( a==0) return b;
  else gcd_fast(b,a%b);
}
int main() {
  long long a, b;
  std::cin >> a >> b;
  
//#define __STRESS_TEST__
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {

    long long  val1 = rand() % a ;
    long long  val2 = rand() % b ;
    
    long long  naive =  gcd_naive(val1,val2);
    long long  fast =  gcd_fast(val1,val2);
    if( naive != fast)
    {
      cout<<val1<<":"<<val2<<" Wrong Answer: " << naive <<" , "<<fast<<endl;
      return 0;
    }
    else
      cout <<val1<<":"<<val2<<" Correct :"<<naive<<" - "<<fast<<endl;
  }


//STRESS TEST
#endif
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
