
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle 
 * Statement: Maximum Pairwise Product Problem
 * Description: Find the maximum product of two distinct numbers
 *          in a sequence of non-negative integers..
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;
using std::cin;
using std::cout;
using std::max;

unsigned long int MaxPairwiseProduct_Naive(const std::vector<unsigned long int>& numbers) {
  unsigned long int product = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      product = max(product, numbers[i] * numbers[j]);
    }
  }
  return product;
}

unsigned long int MaxPairwiseProduct(std::vector<unsigned long int>& numbers) {
    unsigned long int max_product = 0;
    int n = numbers.size();

    unsigned long int i_val1=0;
    unsigned long int i_val2=0;

    for (int first = 1; first < n; ++first) {
      if(numbers[i_val1] < numbers[first])
        i_val1 = first;
    }

    unsigned long int temp = numbers[n-1];
    numbers[n-1] = numbers[i_val1];
    numbers[i_val1] = temp;

    for (int second = 1; second < n-1; ++second) {
      if(numbers[i_val2] < numbers[second])
        i_val2 = second;
    }

    return numbers[n-1] * numbers[i_val2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<unsigned long int> numbers(n);

//Stress Test
#ifdef __STRESS_TEST__
while (1)
{
    for (int i = 0; i < n; ++i) {
        unsigned long int val = rand() % 100000 + 1;
        numbers[i] = val;
    }
    for (int i = 0; i < n; ++i) {
      cout<<numbers[i]<<" ";
    }
    cout<<endl<<endl;

    unsigned long int naive =  MaxPairwiseProduct_Naive(numbers);
    unsigned long int fast = MaxPairwiseProduct(numbers);
    if( naive != fast)
    {
      cout<<" Wrong Answer: " << naive <<" , "<<fast<<endl;
      return 0;
    }
    else
      cout <<" OK"<<endl;


}
#endif
//Stress Test

    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    unsigned long int result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
