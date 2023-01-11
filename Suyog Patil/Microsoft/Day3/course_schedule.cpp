
class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        vector<int> adj[n];
        for (int i = 0; i < p.size(); i++)
            adj[p[i][1]].push_back(p[i][0]);

        // int inDegree[n] = {0};
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                inDegree[it]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (not q.empty())
        {
            int top = q.front();
            q.pop();

            topo.push_back(top);
            for (auto it : adj[top])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return (topo.size() == n);
    }
};
