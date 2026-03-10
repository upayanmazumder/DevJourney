# Assembly Line Scheduling (Dynamic Programming)

Problem
- Given processing times on two assembly lines and transfer times between stations, find minimum time to process a product and the optimal line choices.

Algorithm
- Dynamic programming: compute best time to reach station i on each line using values from station i-1 and possible transfers.

Time complexity: O(n)
Space complexity: O(n)

Input format (example):
```
4           # number of stations
2 4         # entry times e1 e2
3 2         # exit times x1 x2
7 9 3 4     # a1[1..n]
8 5 6 4     # a2[1..n]
2 3 1       # t1[1..n-1]
2 1 2       # t2[1..n-1]
```

Code: [02_assembly_line_scheduling.cpp](02_assembly_line_scheduling.cpp)
