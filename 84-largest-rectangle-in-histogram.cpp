class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        stack<int> cou;
        int res = 0;
        st.push(0);
        cou.push(0);
        for (auto x : heights) {
            if (x >= st.top()) {
                st.push(x);
                cou.push(0);
            } else {
                int count = 0;
                while (x < st.top()) {
					count = count + cou.top() + 1;
                    if (count * st.top() > res) {
                        res = count * st.top();
                    }
                    st.pop();
					cou.pop();
                }
                cou.push(count);
                st.push(x);
            }
        }
        
        int count = 0;
        while (!st.empty()) {
            count = count + cou.top() + 1;
			if (count * st.top() > res) {
                res = count * st.top();
            }
            st.pop();
			cou.pop();
        }
        
        return res;
    }
};
