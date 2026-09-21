class Solution {
    bool isBreaks(string &a, string &b, unordered_map<char, int> &mp){
        int n = a.size();
        int m = b.size();

        int i = 0;

        while(i < n && i < m){
            if(a[i] != b[i]){
                if(mp[a[i]] > mp[b[i]]){
                    return true;
                }
                return false;
            }
            i++;
        }

        if(n > m)return true;

        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;

        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }

        for(int i = 1; i < words.size(); i++){
            if(isBreaks(words[i-1], words[i], mp)){
                return false;
            }
        }



        return true;
    }
};