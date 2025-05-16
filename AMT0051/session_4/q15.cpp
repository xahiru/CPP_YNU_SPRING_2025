def rotate_layer_clockwise(matrix, k):
    if not matrix or not matrix[0]:
        return matrix
    
    m, n = len(matrix), len(matrix[0])
    layers = min(m, n) // 2

    for layer in range(layers):
        elements = []

        # Top row
        for j in range(layer, n - layer):
            elements.append(matrix[layer][j])
        # Right column
        for i in range(layer + 1, m - layer - 1):
            elements.append(matrix[i][n - layer - 1])
        # Bottom row
        for j in range(n - layer - 1, layer - 1, -1):
            elements.append(matrix[m - layer - 1][j])
        # Left column
        for i in range(m - layer - 2, layer, -1):
            elements.append(matrix[i][layer])

        # Rotate clockwise
        k_mod = k % len(elements)
        elements = elements[-k_mod:] + elements[:-k_mod]

        idx = 0
        # Reassign rotated elements
        for j in range(layer, n - layer):
            matrix[layer][j] = elements[idx]
            idx += 1
        for i in range(layer + 1, m - layer - 1):
            matrix[i][n - layer - 1] = elements[idx]
            idx += 1
        for j in range(n - layer - 1, layer - 1, -1):
            matrix[m - layer - 1][j] = elements[idx]
            idx += 1
        for i in range(m - layer - 2, layer, -1):
            matrix[i][layer] = elements[idx]
            idx += 1

    return matrix


# Example usage
matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

K = 2
rotated_matrix = rotate_layer_clockwise(matrix, K)

print("Rotated Matrix:")
for row in rotated_matrix:
    print(*row)
