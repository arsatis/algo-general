#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

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

// E.g., Contains Duplicate: https://leetcode.com/problems/contains-duplicate/
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> freqCounter;
    for (int i : nums) {
        if (freqCounter.find(i) == freqCounter.end()) return true;
        freqCounter.insert(i);
    }
    return false;
}

// E.g., Two Sum: https://leetcode.com/problems/two-sum/
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> freqCounter;
    for (int i : nums) {
        if (freqCounter.find(nums[i]) != freqCounter.end())
            return { i, freqCounter[nums[i]] };
        freqCounter[target - nums[i]] = i;
    }
    return {};
}

int main() {
    vector<string> v = { "abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba",
                         "aabcd", "aaaa", "", "abcda" };
    vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 1 };

    cout << longestPalindrome(v[0]) << " " << longestPalindrome(v[2]) << " "
         << longestPalindrome(v[3]) << " " << longestPalindrome(v[4]) << "\n";
    cout << (validAnagram(v[0], v[1]) ? "true" : "false") << "\n";
    for (auto& vec : groupAnagrams(v)) {
        for (string& s : vec) cout << s << " ";
        cout << "| ";
    }
    cout << "\n";

    cout << (containsDuplicate(vi) ? "true" : "false") << "\n";
    cout << twoSum(vi, 12)[0] << " " << twoSum(vi, 12)[1] << "\n";
}