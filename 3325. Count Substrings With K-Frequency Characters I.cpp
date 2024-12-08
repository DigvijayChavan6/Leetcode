// Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.

// A substring is a contiguous non-empty sequence of characters within a string.

 

// Example 1:

// Input: s = "abacb", k = 2

// Output: 4

// Explanation:

// The valid substrings are:

// "aba" (character 'a' appears 2 times).
// "abac" (character 'a' appears 2 times).
// "abacb" (character 'a' appears 2 times).
// "bacb" (character 'b' appears 2 times).
// Example 2:

// Input: s = "abcde", k = 1

// Output: 15

// Explanation:

// All substrings are valid because every character appears at least once.

 

// Constraints:

// 1 <= s.length <= 3000
// 1 <= k <= s.length
// s consists only of lowercase English letters.

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int cnt = 0;
        int size = s.size();
        for(int i=0; i<size; ++i){
            int flag = false;
            unordered_map<char, int> mp;
            for(int j=i; j<size; ++j){
                ++mp[s[j]];
                if(mp[s[j]] >= k || flag){
                    flag = true;
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};