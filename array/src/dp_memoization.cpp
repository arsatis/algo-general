/**
 * Idea:
 * 1. Start with the recursive backtracking solution
 * 2. Optimize by using a memoization table (top-down dynamic programming)
 * 3. Remove the need for recursion (bottom-up dynamic programming)
 * 4. Apply final tricks to reduce the time/memory complexity
 * Requires: problems with the overlapping subproblems or optimal substructure property.
 */
#include "../../utils/utils.h"

// E.g., Fibonacci Number: https://leetcode.com/problems/fibonacci-number/
vector<int> memo = { 0, 1 };
int dp(int n) {
    if (memo[n] != -1) return memo[n];
    return memo[n] = dp(n - 1) + dp(n - 2);
}
int fib(int n) {
    memo.resize(n + 1, -1);
    return dp(n);
}

// E.g., N-th Tribonacci Number: https://leetcode.com/problems/n-th-tribonacci-number/
vector<int> memo2 = { 0, 1, 1 };
int dp2(int n) {
    if (memo2[n] != -1) return memo2[n];
    return memo2[n] = dp2(n - 1) + dp2(n - 2) + dp2(n - 3);
}
int tribonacci(int n) {
    memo2.resize(n + 1, -1);
    return dp2(n);
}
