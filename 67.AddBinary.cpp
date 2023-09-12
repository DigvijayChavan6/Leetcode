/*
Given two binary strings a and b, return their sum as a binary string.
 
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string re="";
        int i=a.size()-1,j=b.size()-1,hc=0;
        while(i>=0 && j>=0){
            char ch;
            if(hc==1){
                if(a[i]==b[j]){
                    if(a[i]=='0')hc=0;
                    else hc=1;
                    ch='1';
                }
                else{
                    hc=1;
                    ch='0';
                }
            }
            else{
                if(a[i]==b[j]){
                    if(a[i]=='0')hc=0;
                    else hc=1;
                    ch='0';
                }
                else{
                    hc=0;
                    ch='1';
                }
            }
            re=ch+re;
            i--;
            j--;
        }
        while(i>=0){
            char ch;
            if(hc==1){
                if(a[i]=='1')ch='0';
                else{
                    hc=0;
                    ch='1';
                }
            }
            else{
                if(a[i]=='1')ch='1';
                else ch='0';
            }
            re=ch+re;
            i--;
        }
        while(j>=0){
            char ch;
            if(hc==1){
                if(b[j]=='1')ch='0';
                else{
                    hc=0;
                    ch='1';
                }
            }
            else{
                if(b[j]=='1')ch='1';
                else ch='0';
            }
            re=ch+re;
            j--;
        }
        if(hc==1)re='1'+re;
        return re;
    }
};