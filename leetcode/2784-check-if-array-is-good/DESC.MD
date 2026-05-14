# 2784. Check if Array is Good

You are given an integer array `nums`. We consider an array good if it is a permutation of an array `base[n]`.

`base[n] = [1, 2, ..., n - 1, n, n]` (in other words, it is an array of length `n + 1` which contains `1` to `n - 1` exactly once, plus two occurrences of `n`). For example, `base[1] = [1, 1]` and `base[3] = [1, 2, 3, 3]`.

Return `true` if the given array is good, otherwise return `false`.
### Example 1:

**Input**

`nums = [2, 1, 3]`

**Output**

`false`

### Example 2:

**Input**

`nums = [1, 3, 3, 2]`

**Output**

`true`

### Example 3:

**Input**

`nums = [1, 1]`

**Output**

`true`


### Example 4:

**Input**

`nums = [3, 4, 4, 1, 2, 1]`

**Output**

`false`

### Constraints:

```
1 <= nums.length <= 100
1 <= nums[i] <= 200
```
