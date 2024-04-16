
1. Initialize an array dp of size n + 1 to store the number of ways to construct each sum.
2. Initialize dp[0] to 1, because there's only one way to construct the sum 0 (by not throwing the dice at all).
3. Iterate from 1 to n, updating dp[i] according to the recurrence relation.
4. Return dp[n].
