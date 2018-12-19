
/*
 * Author: Rambabu Yerajana
 * Text:   Algorithm Tool Box 
 * Topic:  Puzzle
 * Problem Statement: Sum of Two Digits Problem 
 * Problem Description: Compute the sum of two single digit numbers.
 * */
#include <iostream>

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

int main() {
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    std::cout << sum_of_two_digits(a, b);
    return 0;
}
