class Solution {
public:
    vector<vector<bool>> g;
    vector<bool> passNodes;
    vector<int> res;
    int l;
        
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
        {
            return true;
        }
        l = numCourses;
        int len = prerequisites.size();
        for (int i = 0; i < numCourses; i++)
        {
            passNodes.push_back(false);
            res.push_back(-1);
        }
        for (int i = 0; i < numCourses; i++)
        {
            g.push_back(passNodes);
        }
        for (int i = 0; i < len; i++)
        {
            g[prerequisites[i].first][prerequisites[i].second] = true;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (res[i] == -1)
            {
                bool flag = dfs(i);
                if (!flag)
                {
                    return false;
                }
                else
                {
                    res[i] = 1;
                }
            }
        }
        
        return true;
    }
    
    bool dfs(int node)
    {
        passNodes[node] = true;
        for (int i = 0; i < l; i++)
        {
            if (g[node][i])
            {
                if (passNodes[i])
                {
                    return false;
                }
                bool flag = dfs(i);
                if (!flag)
                {
                    return false;
                }
                else
                {
                    res[i] = 1;
                }
            }
        }
        passNodes[node] = false;
        return true;
    }
};
