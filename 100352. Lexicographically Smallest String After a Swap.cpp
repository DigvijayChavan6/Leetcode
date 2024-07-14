// Given a string s containing only digits, return the 
// lexicographically smallest string
//  that can be obtained after swapping adjacent digits in s with the same parity at most once.

// Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.

 

// Example 1:

// Input: s = "45320"

// Output: "43520"

// Explanation:

// s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

// Example 2:

// Input: s = "001"

// Output: "001"

// Explanation:

// There is no need to perform a swap because s is already the lexicographically smallest.

 

// Constraints:

// 2 <= s.length <= 100
// s consists only of digits.

class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size(), a=0, b=0;
        string ans=s;
        for(int i=1;i<n;i++){
            a=s[i-1]-48;
            b=s[i]-48;
            string t=s;
            if(a%2 == b%2){
                swap(t[i-1], t[i]);
            }
            if(ans>t){
                ans=t;
            }
        }
        return ans;
    }
};