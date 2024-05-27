#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double generate_random_number() {
    return (double)rand() / RAND_MAX; // Generate a random number between 0 and 1
}

double estimate_pi(int num_samples) {
    int num_points_inside_circle = 0;

    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < num_samples; i++) {
        double x = generate_random_number();
        double y = generate_random_number();

        // Check if the point (x, y) is inside the circle (x^2 + y^2 <= 1)
        if (x * x + y * y <= 1) {
            num_points_inside_circle++;
        }
    }

    // Estimate pi using the ratio of points inside the circle to total points
    return 4.0 * num_points_inside_circle / num_samples;
}

int main() {
    int num_samples = 1000000; // Number of random samples

    // Estimate pi using Monte Carlo simulation
    double estimated_pi = estimate_pi(num_samples);

    // Print the estimated value of pi
    printf("Estimated value of pi: %.6f\n", estimated_pi);

    return 0;
}
