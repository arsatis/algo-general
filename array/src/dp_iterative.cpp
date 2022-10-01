/**
 * As we iterate through the list, keep track of the last k << n states.
 * Similar to tabulation, but minimizes space complexity.
 * Requires: problems with the optimal substructure property.
 */
#include "../../utils/utils.h"

// E.g., Fibonacci Number: https://leetcode.com/problems/fibonacci-number/
int fib(int n) {
    if (n <= 1) return n;
    int prev2 = 1, prev1 = 1;
    while (n-- > 2) swap(prev2 += prev1, prev1);
    return prev1;
}

// E.g., N-th Tribonacci Number: https://leetcode.com/problems/n-th-tribonacci-number/
int tribonacci(int n) {
    if (n <= 1) return n;
    int prev3 = 0, prev2 = 1, prev1 = 1;
    while (n-- > 2) {
        swap(prev3 += (prev2 + prev1), prev1);
        swap(prev3, prev2);
    }
    return prev1;
}

// E.g., Climbing Stairs: https://leetcode.com/problems/climbing-stairs/
int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    while (n-- > 2) swap(prev2 += prev1, prev1);
    return prev1;
}

// E.g., Min Cost Climbing Stairs: https://leetcode.com/problems/min-cost-climbing-stairs/
int minCostClimbingStairs(vector<int>& cost) {
    if (cost.size() < 2) return 0;
    int prev2 = 0, prev1 = 0;
    for (int i = 2; i < cost.size() + 1; ++i) {
        prev2 = min(prev2 + cost[i - 2], prev1 + cost[i - 1]);
        swap(prev2, prev1);
    }
    return prev1;
}

// E.g., Count Number of Ways to Place Houses: https://leetcode.com/problems/count-number-of-ways-to-place-houses/
int countHousePlacements(int n) {
    long prev2 = 1, prev1 = 2, mod = 1e9 + 7;
    while (n-- > 1) swap(prev2 = (prev1 + prev2) % mod, prev1);
    return (prev1 * prev1) % mod;
}

// E.g., House Robber: https://leetcode.com/problems/house-robber/
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int i : nums) {
        prev2 = max(prev2 + i, prev1);
        swap(prev2, prev1);
    }
    return prev1;
}

// E.g., Decode Ways: https://leetcode.com/problems/decode-ways/
int numDecodings(string& s) {
    int prev2, prev1 = 1, n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        int curr = s[i] == '0' ? 0 : prev1; // is the single digit s[i] valid?
        int twoDigit = stoi(s.substr(i, 2));
        if (twoDigit >= 10 && twoDigit <= 26) curr += prev2; // are the two digits s[i:i+1] valid?
        prev2 = prev1;
        prev1 = curr;
    }
    return s.empty() ? 0 : prev1;  
}
