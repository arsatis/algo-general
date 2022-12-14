/**
 * Use a fixed-size array, hashset, or hashmap to keep track of the count of the element at
 * each index of the given array/vector/string.
 */
#include "../../utils/utils.h"

/* Using fixed-size arrays */
// E.g., Longest Palindrome: https://leetcode.com/problems/longest-palindrome/
int longestPalindrome(string& s) {
    int len = 0, freqCounter[64] = { 0 };
    for (char c : s) {
        if (freqCounter[c - 'A'] == 0) ++freqCounter[c - 'A'];
        else --freqCounter[c - 'A'], len += 2;
    }
    return len + (accumulate(freqCounter, freqCounter + 64, 0) > 0);
}

// E.g., Valid Anagram: https://leetcode.com/problems/valid-anagram/
bool validAnagram(string& s, string& t) {
    int freqCounter[26] = { 0 };
    for (char c : s) ++freqCounter[c - 'a'];
    for (char c : t) if (freqCounter[c - 'a']-- == 0) return false;
    return accumulate(freqCounter, freqCounter + 26, 0) == 0;
}

// E.g., Group Anagrams: https://leetcode.com/problems/group-anagrams/
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagrams;
    for (string& s : strs) {
        string key = "";
        int freqCounter[26] = { 0 };
        for (char c : s) ++freqCounter[c - 'a'];
        for (int i : freqCounter) key += i + ".";
        anagrams[key].emplace_back(s);
    }

    vector<vector<string>> output;
    for (auto& [key, vec] : anagrams) output.emplace_back(vec);
    return move(output);
}

/* Using hashset */
// E.g., Contains Duplicate: https://leetcode.com/problems/contains-duplicate/
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freqCounter;
    for (int i : nums) {
        if (freqCounter.find(i) == freqCounter.end()) return true;
        freqCounter.insert(i);
    }
    return false;
}

/* Using hashmap */
// E.g., Minimum Rounds to Complete All Tasks: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> freqCounter;
    for (int i : tasks) ++freqCounter[i];
    
    int rounds = 0;
    for (auto& p : freqCounter) {
        if (p.second == 1) return -1;
        rounds += ceil(p.second / 3.);
    }
    return rounds;
}
