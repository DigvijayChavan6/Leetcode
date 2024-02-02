// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
 

// Constraints:

// 10 <= low <= high <= 10^9

class Solution {
public:
    bool isSd(int val){
        int r=val%10;
        val/=10;
        while(val != 0){
            if(val%10 != r-1)return false;
            r=val%10;
            val/=10;
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vec;
        for(int i=low;i<=high;i++){
            if(isSd(i)){
                vec.push_back(i);
            }
        }
        return vec;
    }
};

// OPTIMISED

class Solution {
public:
    int getNum(int len, int fst){
        int val=0;
        while(len>0){
            val=val*10 + fst;
            fst++;
            len--;
        }
        return val;
    }
    bool isSd(int val){
        int r=val%10;
        val/=10;
        while(val != 0){
            if(val%10 != r-1)return false;
            r=val%10;
            val/=10;
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> vec;
        int val=low,fst=0,len=0,add=0;
        while(val != 0){
            fst=val%10;
            val/=10;
            len++;
            add=add*10 + 1;
        }
        for(int i=getNum(len,fst);i<=high;i+=add){
            if(i<=high && i>=low && isSd(i))vec.push_back(i);
            if(i%10 == 9){
                i=getNum(++len,1);
                if(i<=high && isSd(i))vec.push_back(i);
                add=add*10 + 1;
                if(len>=9)break;
            }
        }
        return vec;
    }
};

// MOST OPTIMISED

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int> vec;
        for(int i=0;i<9;i++){
            string num="";
            for(int j=i;j<9;j++){
                num+=s[j];
                int val=stoi(num);
                if(val<=high && val>=low)vec.push_back(val);
            }
        }
        sort(vec.begin(),vec.end());
        return vec;
    }
};