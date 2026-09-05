class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> ans;
        ans.reserve(numCourses);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans.push_back(u);

            for (int v : graph[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};