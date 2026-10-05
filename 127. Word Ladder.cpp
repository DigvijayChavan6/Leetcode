class Solution {
    bool isEdge(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                cnt++;
        }
        return cnt == 1;
    }

public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        bool begExt = false;
        bool endExt = false;

        for(string &st : wordList){
            if(beginWord == st)begExt = true;
            if(endWord == st)endExt = true;
        }

        if(begExt == false)wordList.push_back(beginWord);
        if(endExt == false)return 0;

        unordered_map<string, int> mp;
        int V = wordList.size();
        
        for (int i = 0; i < V; i++) {
            mp[wordList[i]] = i;
        }

        vector<vector<int>> graph(V);

        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                if (isEdge(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, false);
        queue<int> q;
        int distance = 0;

        q.push(mp[beginWord]);
        visited[mp[beginWord]] = true;

        while (!q.empty()) {

            int level = q.size();
            distance++;

            for (int i = 0; i < level; i++) {
                int node = q.front();
                q.pop();
                if (node == mp[endWord])
                    return distance;

                for (int nbr : graph[node]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }

        return 0;
    }
};