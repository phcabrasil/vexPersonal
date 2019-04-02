import numpy as np
import matplotlib.pyplot as plt

# Arbitrary constants
TIMESTEP    = 1
ACCEL       = 10
ITERATIONS  = 100

# State vector
x = np.array([0,0,ACCEL])

# State transition matrix
a = np.array([[1, TIMESTEP,0], 
              [0, 1,       TIMESTEP], 
              [0, 0,       1]])

# Distances over time
d = np.zeros(ITERATIONS)

# Run the system for the specified number of iterations
for t in range(ITERATIONS):
    x = np.dot(a, x)
    d[t] = x[0]

# Plot distance over time
plt.plot(d)
plt.xlabel('Time')
plt.ylabel('Distance')
plt.show()
