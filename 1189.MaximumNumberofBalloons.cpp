// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:

// Input: text = "nlaebolko"
// Output: 1

// Example 2:

// Input: text = "loonbalxballpoon"
// Output: 2

// Example 3:

// Input: text = "leetcode"
// Output: 0

 

// Constraints:

//     1 <= text.length <= 104
//     text consists of lower case English letters only.

class Solution
{
public:
    int maxNumberOfBalloons(string t)
    {
        map<char, int> bl, tx;
        string s = "balloon";
        for (int i = 0; i < s.size(); i++)
        {
            bl[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            tx[t[i]]++;
        }
        int cnt = tx['b'];
        s = "balon";
        for (int i = 0; i < s.size(); i++)
        {
            if (cnt > (tx[s[i]] / bl[s[i]]))
                cnt = tx[s[i]] / bl[s[i]];
        }
        return cnt;
    }
};