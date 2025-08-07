class Solution {
public:
    // DSU - Union Find structure
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[py] = px;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i

        // Union the connected indices
        for (auto& p : pairs) {
            unite(p[0], p[1]);
        }

        // Group all indices with the same root
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; ++i) {
            groups[find(i)].push_back(i);
        }

        // Create a result string
        string res = s;

        // For each group, sort the characters and reassign
        for (auto& g : groups) {
            vector<int>& indices = g.second;
            string chars;

            for (int idx : indices) {
                chars += s[idx];
            }

            sort(chars.begin(), chars.end());
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); ++i) {
                res[indices[i]] = chars[i];
            }
        }

        return res;
    }
};


