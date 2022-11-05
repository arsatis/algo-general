/**
 * We can model the problem as a finite state machine (FSM) having a number of states.
 * As we iterate through the array/vector, we update each state based on the connections in the FSM.
 */
#include "../../utils/utils.h"

// E.g., Best Time to Buy and Sell Stock: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int maxProfit(vector<int>& prices) {
    int sold = 0, bought = INT_MIN;
    for (int x : prices) {
        bought = max(bought, -x);
        sold = max(sold, bought + x);
    }
    return sold;
}

// E.g., Best Time to Buy and Sell Stock II: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit(vector<int>& prices) {
    int sold = 0, bought = INT_MIN;
    for (int x : prices) {
        bought = max(bought, sold - x);
        sold = max(sold, bought + x);
    }
    return sold;
}

// E.g., Best Time to Buy and Sell Stock III: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
int maxProfit(vector<int>& prices) {
    int sold[2] = {}, bought[2] = {INT_MIN, INT_MIN};
    for (int x : prices) {
        bought[0] = max(bought[0], -x);
        sold[0] = max(sold[0], bought[0] + x);
        bought[1] = max(bought[1], sold[0] - x);
        sold[1] = max(sold[1], bought[1] + x);
    }
    return max(sold[0], sold[1]);
}

// E.g., Best Time to Buy and Sell Stock IV: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
int maxProfit(int k, vector<int>& prices) {
    vector<int> sold(k), bought(k, INT_MIN);
    for (int x : prices) {
        for (int i = 0; i < k; ++i) {
            bought[i] = max(bought[i], (i == 0 ? 0 : sold[i - 1]) - x);
            sold[i] = max(sold[i], bought[i] + x);
        }
    }
    return *max_element(sold.begin(), sold.end());
}

// E.g., Best Time to Buy and Sell Stock with Cooldown: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
int maxProfit(vector<int>& prices) {
    int sold = 0, bought = INT_MIN, cooldown = 0;
    for (int x : prices) {
        int tmp = sold;
        sold = max(sold, cooldown);
        bought = max(bought, tmp - x);
        cooldown = bought + x;
    }
    return max(cooldown, sold);
}

// E.g., Best Time to Buy and Sell Stock with Transaction Fee: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
int maxProfit(vector<int>& prices, int fee) {
    int sold = 0, bought = INT_MIN;
    for (int x : prices) {
        int tmp = sold;
        sold = max(sold, bought + x);
        bought = max(bought, tmp - x - fee);
    }
    return sold;
}

// E.g., Maximum Subarray Sum After One Operation: https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/
int maxSumAfterOperation(vector<int>& nums) {
    int sq = 0, no_sq = 0, res = 0;
    for (int x : nums) {
        sq = max(sq + x, no_sq + x * x);
        no_sq = max(0, x + no_sq);
        res = max(res, sq);
    }
    return res;
}
