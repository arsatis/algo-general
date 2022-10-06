/**
 * Hash the first k elements of a string: as you move along each element,
 * - multiply the current hash by some factor (>= the max possible value across all elements)
 * - add the next element to the current hash
 * - take the mod of the current hash against some prime (as large as possible, while preventing overflow)
 * 
 * Then, for each of the remaining elements in the string,
 * - remove the leftmost/earliest element that was added to the hash
 * - add the next element to the hash (in a similar manner as above)
 * 
 * Leetcode list: https://leetcode.com/tag/rolling-hash/
 */
#include "../../utils/utils.h"

// General structure of Rabin-Karp
void rabinKarp(string& s, int k) {
    int shift = 5;      // shift factor
    int mod = 5e7 + 17; // prime to take mod against
    int multiplier = 1; // multiplier to help remove the leftmost element from the hash
    int sHash = 0;      // current hash
    
    // compute the value of the multiplier
    for (int i = 1; i < k; ++i) multiplier = (multiplier << shift) % mod;

    // hash the first k elements
    for (int i = 0; i < k; ++i) sHash = ((sHash << shift) + s[i] - 'a') % mod;
    
    // hash the remaining elements
    for (int i = k; i < s.size(); ++i) {
        sHash = (sHash + mod - (multiplier * (s[i - k] - 'a') % mod)) % mod; // remove leftmost element
        sHash = ((sHash << shift) + s[i] - 'a') % mod;                       // add rightmost element
    }
}

// E.g., Repeated Substring Pattern: https://leetcode.com/problems/repeated-substring-pattern/
bool isSubstring(string& s, string& t) { // s: source (longer string), t: target (shorter string)
    int shift = 5, mod = 1e7 + 19, multiplier = 1, k = t.size();
    int sHash = 0, tHash = 0;
    
    for (int i = 1; i < k; ++i) multiplier = (multiplier << shift) % mod;
    for (int i = 0; i < k; ++i) {
        sHash = ((sHash << shift) + s[i] - 'a') % mod;
        tHash = ((tHash << shift) + t[i] - 'a') % mod;
    }
    
    if (sHash == tHash) return true;
    for (int i = k; i < s.size(); ++i) {
        sHash = (sHash + mod - (multiplier * (s[i - k] - 'a') % mod)) % mod; // remove leftmost element
        sHash = ((sHash << shift) + s[i] - 'a') % mod; // add rightmost element
        if (sHash == tHash) return true;
    }
    return false;
}
bool repeatedSubstringPattern(string s) {
    string s2 = (s + s).substr(1, s.size() - 1 << 1);
    return isSubstring(s2, s);
}

// E.g., Repeated String Match: https://leetcode.com/problems/repeated-string-match/
int repeatedStringMatch(string& a, string& b) {
    int count = 0;
    string s = "";
    while (s.size() < b.size()) s += a, ++count;
    if (isSubstring(s, b)) return count;
    if (isSubstring(s += a, b)) return count + 1;
    return -1;
}

// E.g., Find the Index of the First Occurrence in a String: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
int strStr(string haystack, string needle) {
    int shift = 5, mod = 1e7 + 19, multiplier = 1, k = needle.size();
    int nHash = 0, hHash = 0;
    
    for (int i = 1; i < k; ++i) multiplier = (multiplier << shift) % mod;
    for (int i = 0; i < k; ++i) {
        nHash = ((nHash << shift) + needle[i] - 'a') % mod;
        hHash = ((hHash << shift) + haystack[i] - 'a') % mod;
    }
    
    if (hHash == nHash) return 0;
    for (int i = k; i < haystack.size(); ++i) {
        hHash = (hHash + mod - (multiplier * (haystack[i - k] - 'a') % mod)) % mod; // remove leftmost element
        hHash = ((hHash << shift) + haystack[i] - 'a') % mod; // add rightmost element
        if (hHash == nHash) return i - k + 1;
    }
    return -1;
}

// E.g., Longest Duplicate Substring: https://leetcode.com/problems/longest-duplicate-substring/
string dupWithLength(string& s, int k) {
    unordered_map<int, int> hashes;
    int shift = 5, mod = 5e7 + 17, multiplier = 1, sHash = 0;
    
    for (int i = 1; i < k; ++i) multiplier = (multiplier << shift) % mod;
    for (int i = 0; i < k; ++i) sHash = ((sHash << shift) + s[i] - 'a') % mod;
    hashes[sHash] = k - 1;
    
    for (int i = k; i < s.size(); ++i) {
        sHash = (sHash + mod - (multiplier * (s[i - k] - 'a') % mod)) % mod; // remove leftmost element
        sHash = ((sHash << shift) + s[i] - 'a') % mod; // add rightmost element
        if (hashes.find(sHash) != hashes.end() &&
            s.substr(i - k + 1, k) == s.substr(hashes[sHash] - k + 1, k)) return s.substr(i - k + 1, k);
        hashes[sHash] = i;
    }
    return "";
}
string longestDupSubstring(string& s) {
    int lo = 0, hi = s.size() - 1;
    string maxDup = "", dup;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if ((dup = dupWithLength(s, mid)) == "") hi = mid - 1;
        else {
            lo = mid;
            if (mid > maxDup.size()) maxDup = dup;
        }
    }
    return maxDup;
}

// E.g., Longest Happy Prefix: https://leetcode.com/problems/longest-happy-prefix/
string longestPrefix(string& s) {
    int shift = 5, mod = 1e7 + 19, multiplier = 1, k = s.size();
    int sHash = 0, tHash = 0, maxLen = 0;
    for (int i = 0; i < k - 1; ++i) {
        sHash = ((sHash << shift) + (s[i] - 'a')) % mod;
        tHash = (tHash + multiplier * (s[k - 1 - i] - 'a')) % mod;
        multiplier = (multiplier << shift) % mod;
        if (sHash == tHash) maxLen = i + 1;
    }
    return s.substr(0, maxLen);
}
