class Solution {
public:
    vector<int> topo, vis;
    bool cycle = false;

    void dfs(int u, vector<vector<int>>& adj) 
    {
        vis[u] = 2;  // mark as visiting

        for (auto v : adj[u]) 
        {
            if (vis[v] == 0) 
            {
                dfs(v, adj);

                if (cycle) return;
            } 
            else if (vis[v] == 2) 
            {
                // back edge found — cycle
                cycle = true;
                return;
            }
        }

        vis[u] = 1;  //fully mark the node
        topo.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vis.assign(numCourses, 0);
        topo.clear();

        // Build adjacency list
        for (auto& pre : prerequisites) 
        {
            adj[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) 
        {
            if (vis[i] == 0) 
            {
                dfs(i, adj);

                if (cycle) return {};
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;
    }
};

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);
//         vector<int> topo;

//         // Build adjacency list and indegree array
//         for (auto& pre : prerequisites) 
//         {         
//             adj[pre[1]].push_back(pre[0]);  // edge from pre[1] → pre[0]
//             indegree[pre[0]]++;             // pre[0] has one more prereq
//         }

//         queue<int> q;

//         // Start with courses that have no prerequisites
//         for (int i = 0; i < numCourses; i++) 
            // {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         // Process courses in order of readiness
//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();
//             topo.push_back(curr);

//             for (int u : adj[curr]) {
//                 indegree[u]--;
//                 if (indegree[u] == 0) {
//                     q.push(u);
//                 }
//             }
//         }

//         // If not all courses were added → cycle detected
//         if (topo.size() != numCourses) return {};

//         return topo;
//     }
// };

