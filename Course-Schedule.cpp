class Solution 
{
    vector<int> vis,levels,indegree,topo;
    vector<vector<int>> adj;

    void bfs(int numCourses)
    {
        queue<int> q;

        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
                levels[i] = 1;
            }
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            topo.push_back(curr);

            for(auto v: adj[curr])
            {
                indegree[v]--;

                if(indegree[v] == 0)
                {
                    q.push(v);
                    vis[v]= 1;
                    levels[v] = levels[curr] + 1;
                }
            }
        }
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        adj.resize(numCourses); // Resize to numCourses
        vis.resize(numCourses, 0);
        levels.resize(numCourses, 0);
        indegree.resize(numCourses, 0);

        for(auto& pre : prerequisites)
        {
            int course = pre[0];
            int prereq = pre[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        bfs(numCourses);

        return topo.size() == numCourses;
    }
};