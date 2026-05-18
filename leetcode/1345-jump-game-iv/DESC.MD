# 1345. Jump Game IV

Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:

`i + 1` where: `i + 1 < arr.length`.
`i - 1` where: `i - 1 >= 0`.
`j` where: `arr[i] == arr[j]` and `i != j`.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

### Example 1:

**Input**

`arr = [100,-23,-23,404,100,23,23,23,3,404]`

**Output**

`3`

**Explanation**

path through indices 0 -> 4 -> 3 -> 9

### Example 2:

**Input**

`arr = [7]`

**Output**

`0`

**Explanation**

Path of length 0

### Example 3:

**Input**

`arr = [7, 6, 9, 6, 9, 6, 9, 7]`

**Output**

`1`

**Explanation**

Jump directly from first index to the last one as arr[0] == arr[arr.size() - 1].

### Constraints:

```
1 <= arr.length <= 5 * 10 ^ 4
-10^8 <= arr[i] <= 10^8
```
