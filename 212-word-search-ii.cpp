class myTreeNode
{
public:    
    string cur_word;
    myTreeNode* children[26];
    
    myTreeNode(){
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        cur_word = "";
    }
    
    void insertWord(string s){
        int len = s.length();
        if (len == 0)
        {
            return;
        }
        myTreeNode* cur = this;
        for (int i = 0; i < len; i++)
        {
            char c = s[i];
            if (cur->children[c - 'a'] == NULL)
            {
                myTreeNode* p = new myTreeNode();
                cur->children[c - 'a'] = p;
                cur = p;
            }
            else
            {
                cur = cur->children[c - 'a'];
            }
        }
        cur->cur_word = s;
    }
};

class Solution {
public:
    int row;
    int col;
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int len = words.size();
        row = board.size();
        res.clear();
        if (len == 0 || row == 0)
        {
            return res;
        }
        col = board[0].size();
        if (col == 0)
        {
            return res;
        }
        myTreeNode* root = new myTreeNode();
        for (int i = 0; i < len; i++)
        {
            root->insertWord(words[i]);
        }
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                dfs(i, j, root, board);
            }
        }
        
        return res;
    }
    
    void dfs(int i, int j, myTreeNode* p, vector<vector<char>>& board)
    {
        if (i <= -1 || j <= -1 || i >= row || j >= col)
        {
            return;
        }
        char c = board[i][j];
        if (c == '\0')
        {
            return;
        }
        
        if (p->children[c - 'a'] == NULL)
        {
            return;
        }
        else
        {
			myTreeNode* q = p->children[c - 'a'];
			if (q->cur_word != "")
            {
                res.push_back(q->cur_word);
                q->cur_word = "";
            }
            board[i][j] = '\0';
            dfs(i + 1, j, q, board);
            dfs(i - 1, j, q, board);
            dfs(i, j + 1, q, board);
            dfs(i, j - 1, q, board);
            board[i][j] = c;
        }
    }
};
