import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Load the data
data = pd.read_csv('summary.csv', header=None, names=['x', 'y', 'value'])

# Find the max range for x and y coordinates
max_x = data['x'].max()
max_y = data['y'].max()

# Create a zero-filled matrix
heatmap_data = np.zeros((max_x + 1, max_y + 1))

# Populate the matrix with your data
for _, row in data.iterrows():
    heatmap_data[int(row['x']), int(row['y'])] = row['value']

# Plot the heatmap with reversed colors
plt.imshow(heatmap_data, cmap='hot_r')
plt.colorbar()
plt.title('Heatmap Visualization for Reduced Communication Percentage')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')

plt.ylim(0, max_y + 1)

# Save the figure as a PDF
plt.savefig('visualization.pdf', format='pdf')

# Close the plot
plt.close()
