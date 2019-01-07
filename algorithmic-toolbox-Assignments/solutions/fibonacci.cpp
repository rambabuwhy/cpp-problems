
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: compute a small Fibonacci number
 * Description: the definition of Fibonacci sequence: 𝐹0 = 0, 𝐹1 = 1, and 𝐹𝑖 = 𝐹𝑖−1 +𝐹𝑖−2 for
 * 𝑖 ≥ 2. Your goal in this problem is to implement an efficient algorithm for computing
 * Fibonacci numbers. The starter files for this problem contain an implementation of the following naive.
 * */

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
 using namespace std;
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

long long fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long  fibonacci_fast( int n) {
    // write your code here
       if (n <= 1)
          return n;
       vector<long long > fa(n+2);
       fa[0] = 0;
       fa[1] = 1;
       for ( int i = 2 ; i <= n ; i++)
       {
        fa[i] = fa[i-1] + fa[i-2];
       }
       return fa[n];

}

long long  fibonacci_fast_s( int n) {
    // write your code here
      if (n <= 1)
        return n;
      long long first = 0;
      long long second = 1;
       for ( int i = 2 ; i <= n ; i++)
       {
         long long temp = first;
         first = second;
         second = temp + second;
       }

       return second;

}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
//#define __STRESS_TEST__
#ifdef __STRESS_TEST__
//STRESS TEST
  while(true)
  {

    int val = rand() % n + 1;
    
    int naive =  fibonacci_naive(val);
    int fast = fibonacci_fast_s(val);
    if( naive != fast)
    {
      cout<<" N: "<<val<<" Wrong Answer: " << naive <<" , "<<fast<<endl;
      return 0;
    }
    else
      cout <<" N: "<<val<<" Correct :"<<naive<<" - "<<fast<<endl;
  }


//STRESS TEST
#endif
    //std::cout << fibonacci_naive(n) << endl;
    //test_solution();
    std::cout << fibonacci_fast_s(n) << '\n';
    return 0;
}
