class Solution {
    vector<pair<int, int>> edges;

    bool getEdge(string &a, string &b) {
        int n = a.size();
        int m = b.size();

        int i = 0;

        while (i < n && i < m) {

            if (a[i] != b[i]) {
                edges.push_back({a[i] - 'a', b[i] - 'a'});
                return false;
            }

            i++;
        }

        // Invalid case:
        // "abc" comes before "ab"
        if (n > m) {
            return true;
        }

        return false;
    }

public:
    string findOrder(vector<string> &words) {

        bool present[26] = {false};

        // Mark every character present in input
        for (string &word : words) {
            for (char ch : word) {
                present[ch - 'a'] = true;
            }
        }

        // Create edges
        for (int i = 1; i < words.size(); i++) {
            if (getEdge(words[i - 1], words[i])) {
                return "";
            }
        }

        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);

        // Build graph
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Only consider characters actually present
        int totalCharacters = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                totalCharacters++;

                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        string order = "";

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            order += char(node + 'a');

            for (int nbr : graph[node]) {

                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // Cycle detected
        if (order.size() != totalCharacters) {
            return "";
        }

        return order;
    }
};