class Solution {
public:
    vector<vector<bool>> g;
    vector<int> inNodes;
    vector<int> res;
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        res.clear();
        if (numCourses == 0)
        {
            return res;
        }
        int len = prerequisites.size();
        vector<bool> temp;
        for (int i = 0; i < numCourses; i++)
        {
            temp.push_back(false);
            inNodes.push_back(0);
        }
        for (int i = 0; i < numCourses; i++)
        {
            g.push_back(temp);
        }
        for (int i = 0; i < len; i++)
        {
            g[prerequisites[i].first][prerequisites[i].second] = true;
            inNodes[prerequisites[i].first]++;
        }
        vector<int> calNodes;
        for (int i = 0; i < numCourses; i++)
        {
            if (inNodes[i] == 0)
            {
                calNodes.push_back(i);
            }
        }
        int count = 0;
        while (!calNodes.empty())
        {
            int cur = calNodes[0];
            res.push_back(cur);
            count++;
            calNodes.erase(calNodes.begin());
            for (int i = 0; i < numCourses; i++)
            {
                if (g[i][cur])
                {
                    inNodes[i]--;
                    if (inNodes[i] == 0)
                    {
                        calNodes.push_back(i);
                    }
                }
            }
        }
        if (count != numCourses)
        {
            res.clear();
        }
        return res;
    }
};
