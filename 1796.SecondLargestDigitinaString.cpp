// Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

// An alphanumeric string is a string consisting of lowercase English letters and digits.

 

// Example 1:

// Input: s = "dfa12321afd"
// Output: 2
// Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.

// Example 2:

// Input: s = "abc1111"
// Output: -1
// Explanation: The digits that appear in s are [1]. There is no second largest digit. 

 

// Constraints:

//     1 <= s.length <= 500
//     s consists of only lowercase English letters and/or digits.

class Solution
{
public:
    int secondHighest(string s)
    {
        int re = -1, t = 0;
        map<int, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (48 <= ch && ch <= 57)
                mp[ch]++;
        }
        for (int i = 57; i >= 48; i--)
        {
            if (mp.find(i) != mp.end())
                t++;
            if (t == 2)
                return i - 48;
        }
        return re;
    }
};