// You are given a string target.

// Alice is going to type target on her computer using a special keyboard that has only two keys:

// Key 1 appends the character "a" to the string on the screen.
// Key 2 changes the last character of the string on the screen to its next character in the English alphabet. For example, "c" changes to "d" and "z" changes to "a".
// Note that initially there is an empty string "" on the screen, so she can only press key 1.

// Return a list of all strings that appear on the screen as Alice types target, in the order they appear, using the minimum key presses.

 

// Example 1:

// Input: target = "abc"

// Output: ["a","aa","ab","aba","abb","abc"]

// Explanation:

// The sequence of key presses done by Alice are:

// Press key 1, and the string on the screen becomes "a".
// Press key 1, and the string on the screen becomes "aa".
// Press key 2, and the string on the screen becomes "ab".
// Press key 1, and the string on the screen becomes "aba".
// Press key 2, and the string on the screen becomes "abb".
// Press key 2, and the string on the screen becomes "abc".
// Example 2:

// Input: target = "he"

// Output: ["a","b","c","d","e","f","g","h","ha","hb","hc","hd","he"]

 

// Constraints:

// 1 <= target.length <= 400
// target consists only of lowercase English letters.

class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> answer;
        vector<string> alpha(27, "");
        for(int i=0; i<26; ++i){
            char c = 97+i;
            alpha[i+1]=string(1, c);
        }
        int size = target.size(), i=0, j=0, alp=1;
        string s="a";
        while(i<size && s != target){
            answer.push_back(s);
            ++alp;
            if(target[i] == s[j]){
                alp=1;
                s+=alpha[alp];
                ++i;
                ++j;
            }else{
                s[i]=alpha[alp][0];
            }
            if(s == target)break;
        }
        answer.push_back(s);
        return answer;
    }
};