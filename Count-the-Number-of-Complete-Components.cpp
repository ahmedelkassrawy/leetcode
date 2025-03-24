class Solution {
public:
    vector<bool>vis;
    vector<vector<int>>adj;
    void dfs(int u,vector<int>&comp)
    {
        vis[u] = 1;
        comp.push_back(u);

        for(auto v : adj[u])
        {
            if(!vis[v])
            {
                dfs(v,comp);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        vis.assign(n, 0);
        adj.assign(n, vector<int>());

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        for(int i = 0; i < n ; i++)
        {
            if(!vis[i])
            {
                vector<int> comp;
                dfs(i,comp);

                bool iscomp = true;
                for(auto u : comp)
                    if(adj[u].size() != comp.size() -1)
                    {
                        iscomp = false;
                        break;
                    }

                if(iscomp) ans++;
            }
        }
        return ans;
    }
};