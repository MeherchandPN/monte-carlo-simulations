# Monte Carlo Simulations

This repository contains implementations of Monte Carlo simulations in C programming language. Monte Carlo simulations are computational techniques that use random sampling to estimate numerical results. The simulations included here cover various applications, such as estimating π, option pricing, and more.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Examples](#examples)
- [License](#license)

## Overview

Monte Carlo simulations are powerful tools used across various fields to approximate the behavior of complex systems or to estimate numerical values. In this repository, we provide implementations of Monte Carlo simulations in C, along with explanations of the underlying principles and applications.

## Usage

Each Monte Carlo simulation is implemented in a separate C file. You can compile and run the simulations using a C compiler such as GCC. Here are the steps to compile and run the simulations:

1. Clone the repository to your local machine:

   ```bash
   git clone https://github.com/MeherchandPN/monte-carlo-simulations.git
   ```

2. Navigate to the directory containing the desired simulation:

   ```bash
   cd monte-carlo-simulations
   ```

3. Compile the C file using GCC:

   ```bash
   gcc -o program_name program_name.c -lm
   ```

   Replace `program_name` with the name of the C file (excluding the `.c` extension).

4. Run the compiled program:

   ```bash
   ./program_name
   ```

   Follow any additional instructions provided in the program's comments or output.
---

## Examples

### 1. Estimate π

The `estimate_pi.c` program implements a Monte Carlo simulation to estimate the value of π. It generates random points in a unit square and counts the number of points that fall within a quarter circle inscribed within the square. The ratio of points inside the circle to the total points provides an estimate of π.

To run the `estimate_pi.c` program:

```bash
gcc -o estimate_pi estimate_pi.c -lm
./estimate_pi
```

### 2. Option Pricing

The `option_pricing.c` program demonstrates Monte Carlo simulation for option pricing using the Black-Scholes model. It calculates the price of a European call or put option, along with the option's delta, gamma, and vega. Users can specify parameters such as the current stock price, strike price, risk-free interest rate, volatility, time to maturity, number of simulations, and option type.

To compile and run the `option_pricing.c` program for pricing a European call option:

```bash
gcc -o option_pricing option_pricing.c -lm
./option_pricing
```

Follow the prompts to enter the required parameters, such as the current stock price, strike price, etc. The program will then perform the Monte Carlo simulation and provide the estimated option price, delta, gamma, and vega.

To price a European put option, modify the `option_type` variable in the source code to `'P'` before compiling and running the program.

---

Feel free to adjust the instructions based on any specific details or requirements of the option pricing example.

## License

This project is licensed under the [MIT License](LICENSE).

---
