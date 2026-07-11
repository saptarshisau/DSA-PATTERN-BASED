# [Bridge edge in a graph](https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1)
## Medium
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.
Note:

An edge is called a&nbsp;bridge&nbsp;if removing it increases the number of&nbsp;connected components&nbsp;of the graph.
if there’s only one path between&nbsp;c&nbsp;and&nbsp;d&nbsp;(which is the edge itself), then that edge is a&nbsp;bridge.

Examples :
Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3]], c = 1, d = 2
Output: true
Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.Hence, it is a Bridge.

Input: V = 5, edges[][] = [[0, 1], [0, 3], [1, 2], [2, 0], [3, 4]], c = 0, d = 2
 Output: false
Explanation:
 Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a green line in the above image.

Constraints:1  ≤  V, E  ≤  1050  ≤  c, d  ≤  V-1