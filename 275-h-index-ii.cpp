class Solution {
public:
    int hIndex(vector<int>& citations) {
        int s = citations.size();
        for (int i = 0; i < s; i++) {
            if (s - i <= citations[i]) {
                return (s - i);
            }
        }
        return 0;
    }
};
