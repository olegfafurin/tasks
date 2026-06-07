# Optimize a numeric sequence

There are two sequences of integers, `u` and `v`, both of size `n > 0`.
One can choose a constant int `shift` and add to each element of `v`. Find an optimal `shift`
according to a specific optimization criteria and modify the sequence `v` in-place so that the
resulting updated sequence `v` is optimal.

1. $\min \sum_{i=0}^{n}|u[i] - v[i]|$

2. $\min \sum_{i=0}^{n}(u[i] - v[i])^2$

The interface to implement is as follows:

`void optimize(const std::vector<int>& u, std::vector<int>& v);`

