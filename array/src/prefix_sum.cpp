/**
 * As we iterate through the array/vector/string, keep track of the sum up till each index.
 * 
 * Leetcode list: https://leetcode.com/tag/prefix-sum/
 */
#include "../../utils/utils.h"

// E.g., Find Pivot Index: https://leetcode.com/problems/find-pivot-index/
int pivotIndex(vector<int>& nums) {
    int prefixSum = 0, sum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); ++i) {
        if (prefixSum == sum - prefixSum - nums[i]) return i;
        prefixSum += nums[i];
    }
    return -1;
}

// E.g., Maximum Sum Score of Array: https://leetcode.com/problems/maximum-sum-score-of-array/
long long maximumSumScore(vector<int>& nums) {
    long long sum = accumulate(nums.begin(), nums.end(), (long long) 0),
              prefixSum = 0, maxSum = LLONG_MIN;
    for (int i : nums) {
        maxSum = max(maxSum, sum - prefixSum);
        prefixSum += i;
        maxSum = max(maxSum, prefixSum);
    }
    return maxSum;
}

// E.g., Subarray Sums Divisible by K: https://leetcode.com/problems/subarray-sums-divisible-by-k/submissions/
int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> count(k);
    count[0] = 1;
    int prefixSum = 0, num = 0;
    for (int i : nums) {
        prefixSum = (prefixSum + i % k + k) % k;
        num += count[prefixSum]++;
    }
    return num;
}

/* Prefix "product" */
// E.g., Product of Array Except Self: https://leetcode.com/problems/product-of-array-except-self/
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) ans[i] = ans[i - 1] * nums[i - 1];
    for (int i = nums.size() - 2, temp = 1; i >= 0; --i) {
        temp *= nums[i + 1];
        ans[i] *= temp;
    }
    return ans;
}
