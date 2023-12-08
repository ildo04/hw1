#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function that checks if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0;  // Numbers 0 and 1 are not considered prime
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;  // If there is a divisor, it is not prime
    }
    return 1;  // If there are no divisors, it is prime
}


// Function that checks if the number is the square of a prime number
int isSquareOfPrime(int n) {
    int squareRoot = sqrt(n);  // Calculate the square root of n

    // Check if n is a perfect square and its square root is a prime number
    return squareRoot * squareRoot == n && isPrime(squareRoot);
}


// Function that reverses the digits of a number
int reverseNumber(int num) {
    int reversed = 0;  // Initialize the reversed number to 0

    while (num > 0) {  // Loop until there are no more digits
        int digit = num % 10;  // Get the last digit of the original number
        reversed = reversed * 10 + digit;  // Add the digit to the reversed number
        num /= 10;  // Remove the last digit from the original number
    }

    return reversed;  // Return the reversed number
}


// Function that checks if the number is recursive
int isPalindrome(int num) {
    int original = num;  // Store the original value of num
    int reversed = 0;    // Initialize a variable to store the reversed number

    // Reverse the digits of num
    while (num > 0) {
        int digit = num % 10;         // Extract the last digit of num
        reversed = reversed * 10 + digit;  // Append the digit to the reversed number
        num /= 10;                   // Remove the last digit from num
    }

    return original == reversed;  // Check if the original number is equal to its reverse
}


int main(int argc, char* argv[]) {
    // Check for the correct number of arguments from the command line
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <lower_bound> <upper_bound>\n", argv[0]);
        return 1;
    }

    unsigned long long lower = atoll(argv[1]);
    unsigned long long upper = atoll(argv[2]);
    
    unsigned long long sum = 0;

    // Iterate from the lower bound to the square of the upper bound
    for (unsigned long long i = lower; i <= upper; i++) {
        int n = i;
        
        
		// Check if it is specular first square and meets other conditions
        if (isSquareOfPrime(n) && reverseNumber(n) && isSquareOfPrime(reverseNumber(n)) && (!(isPalindrome(n)))) {
            sum += n;
        }
    }
    
    // Print the result
    printf("%llu", sum);

    return 0;
}
