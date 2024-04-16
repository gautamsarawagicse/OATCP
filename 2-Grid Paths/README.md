
1. Read the input file to get the grid size n and the grid itself.
2. Initialize a 2D array dp of size n x n to store the number of paths to each cell.
3. Set dp[0][0] to 1 since there's only one way to reach the starting cell.
4. Iterate through each cell (i, j) in the grid:
5. If the current cell is a trap, set dp[i][j] to 0.
6. Otherwise, update dp[i][j] by adding the number of paths from the cell above (i-1, j) and the cell to the left (i, j-1).
7. Finally, return dp[n-1][n-1], which represents the number of paths from the upper-left square to the lower-right square.
