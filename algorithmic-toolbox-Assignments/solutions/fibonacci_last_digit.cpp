
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Last Digit of a Large Fibonacci Number
 * Description: Find the maximum product of two distinct numbers
 *          in a sequence of non-negative integers..
 * */
#include <iostream>
using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    
    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current % 10;
    }

    return current ;
}

int main() {
    int n;
    std::cin >> n;
//#define __STRESS_TEST__ 
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {

    int val = rand() % n + 1;
    
    int naive =  get_fibonacci_last_digit_naive(val);
    int fast = get_fibonacci_last_digit_fast(val);
    if( naive != fast)
    {
      cout<<" N: "<<val<<" Wrong Answer: " << naive <<" , "<<fast<<endl;
      return 0;
    }
    else
      cout <<" N: "<<val<<" Correct :"<<naive<<" - "<<fast<<endl;
  }
#endif
    //int naive = get_fibonacci_last_digit_naive(n);
    int fast = get_fibonacci_last_digit_fast(n);
    std::cout << fast << endl;
    }
