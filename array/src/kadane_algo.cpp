/**
 * As we iterate through the array/vector/string, keep track of:
 * - the current max sum/product, and
 * - the global max sum/product.
 * The current max can be determined by taking max(current max + next val, next val).
 */
#include "../../utils/utils.h"

// E.g., Maximum Subarray: https://leetcode.com/problems/maximum-subarray/
int maxSubArray(vector<int>& nums) {
    int mx = nums[0], curr = 0;
    for (int x : nums) {
        curr = max(x, curr + x);
        mx = max(mx, curr);
    }
    return mx;
}

// E.g., Maximum Sum Circular Subarray: https://leetcode.com/problems/maximum-sum-circular-subarray/
int maxSubarraySumCircular(vector<int>& nums) {
    int total = 0, mx = nums[0], currMax = 0, mn = nums[0], currMin = 0;
    for (int x : nums) {
        currMax = max(currMax + x, x);
        mx = max(mx, currMax);
        currMin = min(currMin + x, x);
        mn = min(mn, currMin);
        total += x;
    }
    return mx > 0 ? max(mx, total - mn) : mx;
}

// E.g., Subarray Sums Divisible by K: https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/
int maxProduct(vector<int>& nums) {
    int minPdt = nums[0], maxPdt = nums[0], mx = nums[0];
    for (int x : nums) {
        if (x < 0) swap(minPdt, maxPdt);
        maxPdt = max(x, maxPdt * x);
        minPdt = min(x, minPdt * x);
        mx = max(mx, maxPdt);
    }
    return mx;
}

// E.g., Product of Array Except Self: https://leetcode.com/problems/product-of-array-except-self/
int getMaxLen(vector<int>& nums) {
    int posLen = 0, negLen = 0, maxLen = 0;
    for (int x : nums) {
        if (x == 0) posLen = 0, negLen = 0;
        else {
            if (x < 0) swap(posLen, negLen);
            if (posLen > 0 || x > 0) ++posLen;
            if (negLen > 0 || x < 0) ++negLen;
            maxLen = max(maxLen, posLen);
        }
    }
    return maxLen;
}
