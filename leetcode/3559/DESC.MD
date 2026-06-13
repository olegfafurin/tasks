3559. Number of Ways to Assign Edge Weights II


There is an undirected tree with `n` nodes labeled from `1` to `n`, rooted at node `1`.
The tree is represented by a 2D integer array `edges` of length `n - 1`, where 
`edges[i] = [u_i, v_i]` indicates that there is an edge between nodes `u_i` and `v_i`.

Initially, all edges have a weight of `0`. You must assign each edge a weight of 
either *1* or *2*.

The cost of a path between any two nodes `u` and `v` is the total weight of 
all edges in the path connecting them.

You are given a 2D integer array `queries`. For each `queries[i] = [u_i, v_i]`, 
determine the number of ways to assign weights to edges in the path such that 
the cost of the path between `u_i` and `v_i` is odd.

Return an array answer, where `answer[i]` is the number of valid assignments for `queries[i]`.

Since the answer may be large, apply modulo `10^9 + 7` to each `answer[i]`.

**Note:** For each query, disregard all edges not in the path between node `u_i` and `v_i`.


### Example 1:

**Input**

`edges = [[1,2]], queries = [[1,1],[1,2]]`

**Output**

`[0, 1]`

**Explanation**
* Query `[1,1]`: The path from Node `1` to itself consists of no edges, so the cost is `0`. 
Thus, the number of valid assignments is `0`.
* Query `[1,2]`: The path from Node `1` to Node `2` consists of one edge `(1 → 2)`. 
Assigning weight `1` makes the cost odd, while `2` makes it even. Thus, the number of valid assignments is 1.


### Example 2:

**Input**

`edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]`

**Output**

`[2, 1, 4]`


### Constraints:

- `2 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i] == [u_i, v_i]`
- `1 <= queries.length <= 10^5`
- `queries[i] == [u_i, v_i]`
- `1 <= u_i, v_i <= n`
- `edges represents a valid tree`

