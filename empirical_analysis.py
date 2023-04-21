import subprocess
import time
import numpy as np
import matplotlib.pyplot as plt

# Define the sizes of the problem to test
n_values = [100, 200, 300, 400, 500, 600]

# Define the number of times to run each algorithm for each problem size
num_trials = 10

# Initialize arrays to hold the results
exhaustive_times = np.zeros((len(n_values), num_trials))
dynamic_times = np.zeros((len(n_values), num_trials))

# Loop over all problem sizes and trials
for i, n in enumerate(n_values):
    for t in range(num_trials):
        # Generate a random set of points
        points = np.random.rand(n, 2)
        
        # Run the exhaustive search algorithm and record the time taken
        start_time = time.time()
        subprocess.run(["./exhaustive3.out"], input=f"{n}\n" + "\n".join([f"{p[0]} {p[1]}" for p in points]), text=True, capture_output=True)
        end_time = time.time()
        exhaustive_times[i, t] = end_time - start_time
        
        # Run the dynamic programming algorithm and record the time taken
        start_time = time.time()
        subprocess.run(["./dynamic3.out"], input=f"{n}\n" + "\n".join([f"{p[0]} {p[1]}" for p in points]), text=True, capture_output=True)
        end_time = time.time()
        dynamic_times[i, t] = end_time - start_time
        
        print(f"Completed trial {t+1}/{num_trials} for n={n}")

# Calculate the mean times for each algorithm and problem size
exhaustive_mean_times = np.mean(exhaustive_times, axis=1)
dynamic_mean_times = np.mean(dynamic_times, axis=1)

# Plot the results
plt.scatter(n_values, exhaustive_mean_times, color="red")
plt.scatter(n_values, dynamic_mean_times, color="blue")

# Fit a curve to the data using a quadratic polynomial
z = np.polyfit(n_values, dynamic_mean_times, 2)
p = np.poly1d(z)
plt.plot(n_values, p(n_values), color="green")

plt.xlabel("Number of moves to goal - bottom right (n)")

plt.ylabel("Mean time taken (seconds)")
plt.title("Dynamic vs. Exhaustive Timing Results - Soccer Opponent Avoidance Algorithms")


plt.legend(["Exhaustive Search", "Dynamic Programming", "Quadratic Fit"])
plt.show()
