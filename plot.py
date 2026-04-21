# Generating plot of Monte Carlo estimates of pi and Gaussian integral vs N (log scale)
import numpy as np
import matplotlib.pyplot as plt
import math


pi_estimates = []
N_values=[]
gauss_estimates = []
with open("x:\IN104_MonteCarloIsing\pi.dat", "r") as f:
    for l in f:
        ligne = [d for d in l.split(" ")]
        pi = float(ligne[0])
        N=int(ligne[1])
        pi_estimates.append(pi)
        N_values.append(N)

with open("x:\IN104_MonteCarloIsing\gauss.dat", "r") as f:
    for l in f:
        ligne = [d for d in l.split(" ")]
        gauss = float(ligne[0])
        gauss_estimates.append(gauss)


# Plotting
plt.style.use('seaborn-v0_8')
plt.figure(figsize=(10, 6))
plt.plot(N_values, pi_estimates, label='Estimate of π', marker='o', markersize=4)
plt.plot(N_values, gauss_estimates, label='Estimate of ∫e^(-x²)dx [-3,3]', marker='s', markersize=4)
plt.axhline(y=np.pi, color='r', linestyle='--', label='π (true value)')
plt.axhline(y=math.sqrt(math.pi), color='g', linestyle='--', label='√π (true value)')
plt.xlabel('Number of samples N (log scale)', fontsize=12)
plt.ylabel('Estimate', fontsize=12)
plt.title('Monte Carlo Estimates of π and Gaussian Integral vs N', fontsize=14)
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('x:\IN104_MonteCarloIsing\monte_carlo_estimates.png')

print("Generated Monte Carlo estimates of π and Gaussian integral for N from 10 to 10000 and saved plot as 'monte_carlo_estimates.png'")