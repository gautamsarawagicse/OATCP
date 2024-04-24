
1. Initialize the flow on each edge to zero.
2. While there exists an augmenting path from the source to the sink:
    * Find an augmenting path using a breadth-first search (BFS) or any other path-finding algorithm.
    * Determine the maximum flow that can be sent along the augmenting path.
    * Update the flow along the augmenting path by incrementing the flow on each edge.
3. Return the maximum flow when no more augmenting paths can be found.

