# Dynamic Programming Problems Categorized by Difficulty

## 🟢 EASY (LeetCode Easy)
These problems focus on fundamental DP concepts with simple state transitions.

| Problem | Files | Concepts | LeetCode |
|---------|-------|----------|----------|
| Fibonacci Sequence | `fibonachi.cpp`<br/>`fibonachiWithTabulation.cpp` | Memoization, Tabulation, Simple Recurrence | Easy |
| Tribonacci Sequence | `tribonachi.cpp` | Memoization, Multiple Recurrence Relations | Easy |
| House Robber I | `houseRobber.cpp` | 1D DP, Maximum Sum, Non-adjacent Selection | Easy |

**Key Characteristics:**
- Simple linear state transitions
- Usually 1D DP arrays
- Clear recurrence relations
- Good starting point for DP learning

---

## 🟡 MEDIUM (LeetCode Medium)
These problems require multi-dimensional thinking and more complex state management.

| Problem | Files | Concepts | LeetCode |
|---------|-------|----------|----------|
| 0/1 Knapsack | `knapsackTabulation.cpp` | 2D DP, Weight-Value Trade-off | Medium |
| Unbounded Knapsack | `unboundedKnapsack.cpp` | Counting variations, Repeated Items | Medium |
| Longest Common Subsequence (LCS) | `LCSMemo.cpp`<br/>`lcsTabulation.cpp`<br/>`longestCommonSubsequence.cpp` | 2D DP, String Matching, Subsequence | Medium |
| Longest Increasing Subsequence (LIS) | `longestIncreasingSubsequence.cpp` | Array DP, Subsequence, O(n²) or O(n log n) | Medium |
| Coin Change - Count Ways | `countWaysRecMem.cpp`<br/>`countWaysTab.cpp`<br/>`countWaysTabVariabtion.cpp` | Unbounded DP, Counting Combinations | Medium |
| Coin Change 2 | `coinChange2.cpp` | Coin Denomination, Combination Counting | Medium |
| Catalan Numbers | `catlanMemo.cpp`<br/>`catlanRec.cpp`<br/>`catlanTabulation.cpp` | Mathematical DP, Catalan Sequence | Medium |
| Mountain Ranges | `mountainRanges.cpp` | Catalan Application, Bracket Arrangements | Medium |
| Target Sum | `targetSum.cpp` | Subset Sum, Array Partition | Medium |
| Road Cutting | `roadCutting.cpp` | Optimization, Cutting Strategy | Medium |

**Key Characteristics:**
- 2D DP tables common
- Multiple decision options at each step
- Requires building up complex subproblems
- String/Array matching scenarios

---

## 🔴 HARD (LeetCode Hard)
These problems require advanced DP techniques and optimization strategies.

| Problem | Files | Concepts | LeetCode |
|---------|-------|----------|----------|
| Edit Distance (Levenshtein) | `editDistance.cpp` | 2D String DP, Insert/Delete/Replace Operations | Hard |
| Matrix Chain Multiplication | `mcm.cpp`<br/>`mcmMemo.cpp`<br/>`mcmTab.cpp` | Interval DP, Optimal Parenthesization | Hard |
| Wildcard Matching | `wildcardMatching.cpp` | Complex String DP, Pattern Matching with `?` and `*` | Hard |
| Minimum Cost to Cut a Stick | `minCostToCutStickRec.cpp`<br/>`minCostToCutStickTab.cpp` | Interval DP, Cost Optimization, Cutting Strategy | Hard |
| Unique Binary Search Trees | `uniqueBinarySearchTrees.cpp` | Catalan Numbers, Tree Construction, Combinatorics | Medium-Hard |

**Key Characteristics:**
- Interval DP / Range DP patterns
- Complex state definitions
- 3D DP tables or nested loops
- Advanced problem-solving strategies required
- Often appear as HackerRank/Google interview questions

---

## Learning Path Recommendation

### Phase 1: Foundation (Easy)
1. `fibonachi.cpp` - Start with basic memoization
2. `fibonachiWithTabulation.cpp` - Learn bottom-up approach
3. `tribonachi.cpp` - Generalize to multiple dependencies
4. `houseRobber.cpp` - First real-world application

### Phase 2: Core Concepts (Medium)
1. `knapsackTabulation.cpp` - Master 2D DP table
2. `lcsTabulation.cpp` - String DP patterns
3. `countWaysTab.cpp` - Counting problems
4. `longestIncreasingSubsequence.cpp` - Subsequence optimization
5. `catlanTabulation.cpp` - Mathematical DP patterns

### Phase 3: Advanced Techniques (Hard)
1. `mcmTab.cpp` - Learn interval DP
2. `editDistance.cpp` - Master string DP
3. `minCostToCutStickTab.cpp` - Advanced interval problems
4. `wildcardMatching.cpp` - Complex pattern matching

---

## Problem Complexity Comparison

```
Easy:        Time: O(n) - Space: O(n)
Medium:      Time: O(n²) or O(n·m) - Space: O(n²) or O(n·m)
Hard:        Time: O(n³) or higher - Space: O(n³) or optimized
```

---

## Tips by Difficulty

**Easy Problems:**
- Identify the base case and recurrence relation
- Practice both memoization and tabulation

**Medium Problems:**
- Define clear DP state (what does dp[i][j] mean?)
- Understand when to iterate over all dimensions
- Practice space optimization

**Hard Problems:**
- Master interval DP pattern
- Understand when O(n³) solutions are acceptable
- Learn to optimize space using rolling arrays
