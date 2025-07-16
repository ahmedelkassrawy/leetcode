class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,vector<int>>> pq;

        vector<vector<int>> ans;

        for(vector<int> v : points)
        {
            int x = v[0];
            int y = v[1];

            int dist = x*x + y*y;
            pq.push({dist,v});

            if(pq.size() > k) pq.pop();
        }

        while(pq.size() > 0)
        {
            vector<int> v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }

        return ans;
    }
};