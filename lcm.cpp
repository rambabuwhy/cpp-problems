
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Least Common Multiple 
 * Description: The least common multiple of two positive integers 𝑎 and 𝑏 is
 * the least positive integer 𝑚 that is divisible by both 𝑎 and 
 * */


#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  if(a == 0 || b == 0 )  return 0;
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(long long  a, long long b) {
  if(b == 0) return a;
  else if ( a==0) return b;
  else gcd_fast(b,a%b);
}

long long lcm_fast(long long a, long long b) {
  if(a == 0 || b == 0 )  return 0;
  return (a * b) / gcd_fast (a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
//#define __STRESS_TEST__
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {

    long long  val1 = rand() % a  ;
    long long  val2 = rand() % b ;
    
    long long  naive =  lcm_naive(val1,val2);
    long long  fast =  lcm_fast(val1,val2);
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
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
