class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 判断是否有环
        vector<int> indegree(numCourses);
        map<int, vector<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];  // b → a
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()) {
            int head = q.front();
            q.pop();
            cnt++;
            for (int j = 0; j < adj[head].size(); j++) {
                indegree[adj[head][j]]--;
                if (!indegree[adj[head][j]]) q.push(adj[head][j]);
            }
        }
        return cnt == numCourses;
    }
};