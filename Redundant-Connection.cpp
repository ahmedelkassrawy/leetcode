class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int node) 
    {
        if(par[node] != node) 
        {
            par[node] = find(par[node]);
        }
        return par[node];
    }

    bool unionset(int n1, int n2) 
    {
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2) return false;

        if(rank[p1] > rank[p2]) 
        {
            par[p2] = p1;
            rank[p1] += rank[p2];
        } 
        else 
        {
            par[p1] = p2;
            rank[p2] += rank[p1];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        par.assign(n + 1, 0);
        rank.assign(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            par[i] = i;
        }

        for(auto edge : edges) {
            if(!unionset(edge[0], edge[1])) 
            {
                return edge;
            }
        }

        return {};
    }
};

//Example:
// edges = {{1, 2}, {1, 3}, {2, 3}};

// Step 1: Union(1, 2) → OK
// Step 2: Union(1, 3) → OK

// Step 3: Union(2, 3) → Already connected through 1 → ❌ cycle detected → return [2, 3]

//find --> 3shan adwrr 3la parents bto3hom 
//lw parent of node is howa nafso khalas kda return 

//union --> lw parents zy b3d y3ny same tree khlas erg3 kda ehna fy cycle
//lw la2 fnta htaa5od element da to7to ta7t akbr parent wtoht rank so8yr m3 kbeer
