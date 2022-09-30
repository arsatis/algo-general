/**
 * Use the input array itself to mark visited numbers (i.e., set corresponding locations as negative).
 * Requires: 1 <= nums[i] <= n.
 */
#include "../../utils/utils.h"

// E.g., Find All Numbers Disappeared in an Array: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> missing;
    for (int i : nums) if (nums[abs(i) - 1] > 0) nums[abs(i) - 1] *= -1;
    for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) missing.emplace_back(i + 1);
    return move(missing);
}

// E.g., Find All Duplicates in an Array: https://leetcode.com/problems/find-all-duplicates-in-an-array/
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> duplicates;
    for (int i : nums) {
        if (nums[abs(i) - 1] < 0) duplicates.emplace_back(abs(i));
        nums[abs(i) - 1] *= -1;
    }
    return move(duplicates);
}

// E.g., First Missing Positive: https://leetcode.com/problems/first-missing-positive/
int firstMissingPositive(vector<int>& nums) {
    for (int& i : nums) if (i < 1) i = nums.size() + 1;
    for (int i : nums) if (abs(i) < nums.size() && nums[abs(i) - 1] > 0) nums[abs(i) - 1] *= -1;
    for (int i = 0; i < nums.size(); ++i) if (nums[i] > 0) return i + 1;
    return nums.size() + 1;
}
