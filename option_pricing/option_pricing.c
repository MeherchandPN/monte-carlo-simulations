#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double normal_distribution(double x) {
    return 0.5 * (1 + erf(x / sqrt(2)));
}

double generate_random_number() {
    return (double)rand() / RAND_MAX; // Generate a random number between 0 and 1
}

double black_scholes_option_price(double S, double K, double r, double sigma, double T, char option_type) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);

    if (option_type == 'C') {
        return S * normal_distribution(d1) - K * exp(-r * T) * normal_distribution(d2);
    } else if (option_type == 'P') {
        return K * exp(-r * T) * normal_distribution(-d2) - S * normal_distribution(-d1);
    } else {
        printf("Error: Invalid option type.\n");
        return 0;
    }
}

void monte_carlo_simulation(double S, double K, double r, double sigma, double T, char option_type, int num_simulations, double *option_price, double *delta, double *gamma, double *vega) {
    double sum_payoffs = 0.0;
    double sum_delta = 0.0;
    double sum_gamma = 0.0;
    double sum_vega = 0.0;

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < num_simulations; i++) {
        double Z = generate_random_number();
        double S_T = S * exp((r - 0.5 * sigma * sigma) * T + sigma * sqrt(T) * Z);
        double payoff;

        if (option_type == 'C') {
            payoff = fmax(S_T - K, 0); // Payoff of a call option
        } else if (option_type == 'P') {
            payoff = fmax(K - S_T, 0); // Payoff of a put option
        } else {
            printf("Error: Invalid option type.\n");
            return;
        }

        sum_payoffs += payoff;
        sum_delta += (payoff > 0) ? 1 : 0;
        sum_gamma += (payoff > 0) ? exp(-r * T) * Z / (S * sigma * sqrt(T)) : 0;
        sum_vega += (payoff > 0) ? exp(-r * T) * S * sqrt(T) * (1 / sqrt(2 * M_PI)) * exp(-0.5 * Z * Z) : 0;
    }

    *option_price = exp(-r * T) * sum_payoffs / num_simulations; // Discounted average payoff
    *delta = sum_delta / num_simulations; // Delta
    *gamma = sum_gamma / num_simulations; // Gamma
    *vega = sum_vega / num_simulations; // Vega
}

int main() {
    // Test case 1: European call option
    double S1 = 100;       // Current stock price
    double K1 = 100;       // Strike price
    double r1 = 0.05;      // Risk-free interest rate
    double sigma1 = 0.2;   // Volatility
    double T1 = 1;         // Time to maturity (in years)
    int num_simulations1 = 1000000; // Number of simulations
    char option_type1 = 'C'; // Option type ('C' for call, 'P' for put)

    double option_price1, delta1, gamma1, vega1;

    // Calculate option price, delta, gamma, and vega using Monte Carlo simulation
    monte_carlo_simulation(S1, K1, r1, sigma1, T1, option_type1, num_simulations1, &option_price1, &delta1, &gamma1, &vega1);

    // Print results for Test case 1
    printf("Test Case 1 (European Call Option):\n");
    printf("Option Price: %.4f\n", option_price1);
    printf("Delta: %.4f\n", delta1);
    printf("Gamma: %.4f\n", gamma1);
    printf("Vega: %.4f\n\n", vega1);

    // Test case 2: European put option
    double S2 = 100;       // Current stock price
    double K2 = 100;       // Strike price
    double r2 = 0.05;      // Risk-free interest rate
    double sigma2 = 0.2;   // Volatility
    double T2 = 1;         // Time to maturity (in years)
    int num_simulations2 = 1000000; // Number of simulations
    char option_type2 = 'P'; // Option type ('C' for call, 'P' for put)

    double option_price2, delta2, gamma2, vega2;

    // Calculate option price, delta, gamma, and vega using Monte Carlo simulation
    monte_carlo_simulation(S2, K2, r2, sigma2, T2, option_type2, num_simulations2, &option_price2, &delta2, &gamma2, &vega2);

    // Print results for Test case 2
    printf("Test Case 2 (European Put Option):\n");
    printf("Option Price: %.4f\n", option_price2);
    printf("Delta: %.4f\n", delta2);
    printf("Gamma: %.4f\n", gamma2);
    printf("Vega: %.4f\n\n", vega2);
    return 0;
}
