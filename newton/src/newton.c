#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to evaluate the value of the polynomial and its derivative
void evaluate_poly(double x, double *result, double *derivative, double coefficients[6]) {
    *result = 0;            // Initialize result
    *derivative = 0;        // Initialize derivative(parag)

    // Loop through polynomial coefficients(suntelestes)
    for (int i = 5; i >= 0; --i) {
        *result += coefficients[i] * pow(x, i); // Evaluate polynomial
        if (i > 0)
            *derivative += i * coefficients[i] * pow(x, i - 1); // Evaluate derivative(parag)
    }
}

// Function to apply the Newton-Raphson algorithm
double newton_raphson(double initial_guess, int max_iterations, double coefficients[6]) {
    double x = initial_guess;   // Initialize x with the initial guess
    double fx, f_prime_x;       // Values of the function and its derivative

    // Iterate through the maximum number of iterations
    for (int i = 0; i < max_iterations; ++i) {
        // Evaluate the function and its derivative
        evaluate_poly(x, &fx, &f_prime_x, coefficients);

        // Termination condition: Convergence based on |xn+1 - xn| < 10^-6
        if (fabs(x - (x - fx / f_prime_x)) < 1e-6) {
            printf("%.2lf\n", x - fx / f_prime_x);
            return x - fx / f_prime_x;
        }

        // Termination condition: Divergence (e.g., division by 0)
        if (isnan(x - fx / f_prime_x)) {
            printf("nan\n");
            return x - fx / f_prime_x;
        }

        // Termination condition: Exceed the maximum number of iterations
        if (i == max_iterations - 1) {
            printf("incomplete.\n");
            return x;
        }

        // Apply the Newton-Raphson algorithm
        x = x - fx / f_prime_x;
    }

    return x;
}

int main(int argc, char *argv[]) {
    // Check for the correct number of command-line arguments
    if (argc != 8) {
        fprintf(stderr, "Incorrect number of arguments. Usage: %s a0 a1 a2 a3 a4 a5 x0\n", argv[0]);
        return 1;
    }

    // Parse coefficients from command-line arguments
    double coefficients[6];
    for (int i = 1; i <= 6; ++i) {
        coefficients[i - 1] = atof(argv[i]);
    }

    double initial_guess = atof(argv[7]);  // Parse the initial guess
    int max_iterations = 1000;             // Set the maximum number of iterations

    // Apply the Newton-Raphson algorithm
    newton_raphson(initial_guess, max_iterations, coefficients);


    return 0;
}
