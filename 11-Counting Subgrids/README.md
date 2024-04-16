
1. Represent each row of the matrix as an integer, where each bit represents the presence of a 1 or 0 in the row.
2. Iterate through each row of the matrix and set the corresponding bits in the integer representation based on the values in the matrix.
3. Iterate through each pair of rows in the matrix.
4. For each pair of rows, calculate the number of common set bits using the bitwise AND operation and the __builtin_popcount function.
5. For each pair of rows, calculate the number of subgrids formed by these rows based on the count of common set bits, and add it to the total count.
