class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        stack<int> st;
        int pre = -1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (pre == -1)
                {
                    pre = s[i] - '0';
                }
                else
                {
                    pre = pre * 10 + (s[i] - '0');
                }
                continue;
            }
            
            if (pre != -1)
            {
                if (st.size() == 0)
                {
                    st.push(pre);
                }
                else
                {
                    int s = st.top();
                    if (s == -3)
                    {
                        st.push(pre);
                    }
                    else if (s == -2)
                    {
                        st.pop();
                        int temp = st.top();
                        st.pop();
                        st.push(temp - pre);
                    }
                    else if (s == -1)
                    {
                        st.pop();
                        int temp = st.top();
                        st.pop();
                        st.push(temp + pre);
                    }
                }
                pre = -1;
            }
            
            if (s[i] == '+')
            {
                st.push(-1);
            }
            else if (s[i] == '-')
            {
                st.push(-2);
            }
            else if (s[i] == '(')
            {
                st.push(-3);
            }
            else if (s[i] == ')')
            {
                int temp = st.top();
                st.pop();
                if (st.top() != -3)
                {
                    return 0;
                }
                st.pop();
                if (st.size() == 0)
                {
                    st.push(temp);
                }
                else
                {
                    int s = st.top();
                    if (s == -3)
                    {
                        st.push(pre);
                    }
                    else if (s == -2)
                    {
                        st.pop();
                        int _temp = st.top();
                        st.pop();
						st.push(_temp - temp);
                    }
                    else if (s == -1)
                    {
                        st.pop();
                        int _temp = st.top();
                        st.pop();
                        st.push(_temp + temp);
                    }
                }
            }
        }
        
        if (st.size() == 0)
        {
            return pre;
        }
        else if (st.size() == 1)
        {
            return st.top();
        }
        else
        {
            int s = st.top();
            if (s == -2)
            {
                st.pop();
                int temp = st.top();
                st.pop();
                return (temp - pre);
            }
            else if (s == -1)
            {
                st.pop();
                int temp = st.top();
                st.pop();
                return (temp + pre);
            }
        }
    }
};
