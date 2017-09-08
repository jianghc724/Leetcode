class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> build;
        for (auto v : buildings) {
            build.push_back(make_pair(v[0], v[2]));
            build.push_back(make_pair(v[1], -v[2]));
        }
        sort(build.begin(), build.end(), [](pair<int, int> a, pair<int, int> b) -> bool {if (a.first != b.first)return a.first < b.first;return a.second > b.second;});
        vector<pair<int, int>> res;
        vector<int> height;
        int h = 0;
        for (auto p : build) {
            if (p.second > 0) {
                add(height, p.second);
                int temp = height.back();
                if (temp != h) {
                    res.push_back(make_pair(p.first, p.second));
                    h = temp;
                }
            } else if (p.second < 0) {
                del(height, -p.second);
                if (!height.empty()) {
                    int temp = height.back();
                    if (temp != h) {
                        res.push_back(make_pair(p.first, temp));
                        h = temp;
                    }
                } else {
                    res.push_back(make_pair(p.first, 0));
                }
            }
        }
        return res;
    }
    
    void add(vector<int>& height, int h) {
        int l = 0;
        int r = height.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (height[m] > h) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        height.insert(height.begin() + l, h);
    }
    
    void del(vector<int>& height, int h) {
        int l = 0;
        int r = height.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (height[m] == h) {
                l = m;
				break;
            }
            else if (height[m] > h) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
		height.erase(height.begin() + l);
    }
};
