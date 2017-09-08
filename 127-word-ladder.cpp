class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        if (len == 0)
        {
            return 0;
        }
        bool flag = true;
        for (int i = 0; i < len; i++)
        {
            if (wordList[i] == endWord)
            {
                wordList.erase(wordList.begin() + i);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return 0;
        }
        queue<pair<string, int>> ladderQueue;
        ladderQueue.push(make_pair(beginWord, 1));
        while (!ladderQueue.empty())
        {
            pair<string, int> cur_pair = ladderQueue.front();
            string cur_str = cur_pair.first;
            int cur_time = cur_pair.second;
            cur_time++;
            ladderQueue.pop();
            if (canConvert(cur_str, endWord))
            {
                return cur_time;
            }
            vector<string>::iterator it = wordList.begin();
            while (it != wordList.end())
            {
                string temp = *it;
                if (canConvert(cur_str, temp))
                {
                    ladderQueue.push(make_pair(temp, cur_time));
                    wordList.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
        return 0;
    }
    
    bool canConvert(string from, string to)
    {
        int f_len = from.length();
        int t_len = to.length();
        if (f_len != t_len)
        {
            return false;
        }
        int dif = 0;
        for (int i = 0; i < f_len; i++)
        {
            if (from[i] != to[i])
            {
                if (dif != 0)
                {
                    return false;
                }
                dif = 1;
            }
        }
        return true;
    }
};
