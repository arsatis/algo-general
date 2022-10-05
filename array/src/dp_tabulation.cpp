/**
 * As we iterate through the list, keep track of the optimal substructure of each state.
 * Requires: problems with the overlapping subproblems or optimal substructure property.
 */
#include "../../utils/utils.h"

// E.g., Fibonacci Number: https://leetcode.com/problems/fibonacci-number/
int fib(int n) {
    if (n <= 1) return n;
    vector<int> memo(n + 1);
    memo[1] = 1;
    for (int i = 2; i <= n; ++i) memo[i] = memo[i - 1] + memo[i - 2];
    return memo.back();
}

// E.g., N-th Tribonacci Number: https://leetcode.com/problems/n-th-tribonacci-number/
int tribonacci(int n) {
    vector<int> memo(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i <= 2) memo[i] = 1;
        else memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
    }
    return memo.back();
}

// E.g., Pascal's Triangle: https://leetcode.com/problems/pascals-triangle/
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> output(numRows, vector<int>(1, 1));
    for (int i = 1; i < numRows; ++i) {
        output[i].reserve(i + 1);
        for (int j = 1; j < i; ++j)
            output[i].emplace_back(output[i - 1][j - 1] + output[i - 1][j]);
        output[i].emplace_back(1);
    }
    return move(output);
}

// E.g., Pascal's Triangle II: https://leetcode.com/problems/pascals-triangle-ii/
vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1, 1); // use O(n) space instead of O(n^2)
    for (int j = 1; j < result.size() - 1; ++j)
        for (int i = rowIndex - 1; i >= j; --i)
            result[i] = result[i + 1] + result[i];
    return move(result);
}
