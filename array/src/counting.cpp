/**
 * In some dp problems, we are required to count the number of ways to perform a certain action.
 * 1. Find the recurrence equation for the ith item, e.g.:
 *    - Coin Change: numWays(i) = 1 + min over all numWays(i - coin)
 *    - Paint Fence: numWays(i) = numWaysDiff(i)           + numWaysSame(i)
 *                              = numWays(i - 1) * (k - 1) + numWaysDiff(i - 1)
 *                              = numWays(i - 1) * (k - 1) + numWays(i - 2) * (k - 1)
 *                              = (numWays(i - 1) + numWays(i - 2)) * (k - 1)
 *    - Unique Paths: numWays(i, j) = numways(i - 1, j) + numWays(i, j - 1)
 * 2. Implement using loops.
 */
#include "../../utils/utils.h"

// E.g., Coin Change: https://leetcode.com/problems/coin-change/
int coinChange(vector<int>& coins, int amount) {
    int dp[10001] = {};
    fill(dp + 1, dp + amount + 1, 10001);
    for (int i = 1; i <= amount; ++i)
        for (int x : coins)
            if (x <= i) dp[i] = min(dp[i], 1 + dp[i - x]);
    return dp[amount] == 10001 ? -1 : dp[amount];
}

// E.g., Coin Change II: https://leetcode.com/problems/coin-change-ii/
int change(int amount, vector<int>& coins) {
    int dp[5001] = {1};
    for (int c : coins)
        for (int i = c; i <= amount; ++i)
            dp[i] += dp[i - c];
    return dp[amount];
}

// E.g., Combination Sum IV: https://leetcode.com/problems/combination-sum-iv/
int combinationSum4(vector<int>& nums, int target) {
    size_t dp[1001] = {1};
    for (int i = 0; i <= target; ++i)
        for (int n : nums)
            if (n <= i) dp[i] += dp[i - n];
    return dp[target];
}

// E.g., Paint Fence: https://leetcode.com/problems/paint-fence/
int numWays(int n, int k) {
    if (n == 1) return k;
    vector<int> numWays(n + 1);
    numWays[1] = k, numWays[2] = k * k;
    for (int i = 3; i <= n; ++i)
        numWays[i] = (numWays[i - 1] + numWays[i - 2]) * (k - 1);
    return numWays[n];
}

// E.g., Unique Paths: https://leetcode.com/problems/unique-paths/
int uniquePaths(int m, int n) {
    int dp[100][100] = {};
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// E.g., Unique Paths II: https://leetcode.com/problems/unique-paths-ii/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid[0][0]) return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[100][100] = {};
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j]) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
