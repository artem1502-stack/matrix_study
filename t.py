import numpy as np

x = np.zeros((5, 5))

with open("test", "r") as f:
	for i in range(5):
		l = np.array(list(map(float, f.readline().split())))
		x[i] = l
print(x)
print(np.linalg.det(x))
