class Node {
public:    
    int value;
    int height;
    int row;
    int col;
    Node* parent;
    Node* next;
	Node* left;
	Node* right;
    bool isUsed;
};

class NodeTree {
public:
    Node* root;
    int row;
    int col;
    
public:
    NodeTree(int r, int c){root = NULL; row = r; col = c;}
    ~NodeTree(){}
    void initialize(Node* nodes);
    int modify(vector<vector<Node*>>& TreeNodes);
};

void NodeTree::initialize(Node* node)
{
    Node* p = node;
    Node* q = node->next;
    Node* r = NULL;
    Node* s = NULL;
    Node* start = NULL;
    int size = 0;
    while (true)
    {
        if (p == NULL)
        {
            if (size <= 1)
            {
                root = s;
                return;
            }
            p = s;
            q = p->next;
            s = NULL;
            r = NULL;
            continue;
        }
        else if (q == NULL)
        {
            Node* t = new Node();
            t->value = p->value;
            t->height = p->height;
            t->row = p->row;
            t->col = p->col;
            t->next = NULL;
            t->parent = NULL;
            p->parent = t;
            r->next = t;
			t->left = p;
            t->isUsed = false;
			t->right = NULL;
            size++;
            p = s;
            q = p->next;
            s = NULL;
            r = NULL;
            continue;
        }
        
        Node* t = new Node();
        Node* temp = NULL;
        if (p->value < q->value)
        {
            temp = p; 
        }
        else
        {
            temp = q;
        }
        
        t->value = temp->value;
        t->height = temp->height;
        t->row = temp->row;
        t->col = temp->col;
        t->next = NULL;
        if (r == NULL)
        {
            size = 0;
			s = t;
        }
        else
        {
            r->next = t;
        }
        t->parent = NULL;
        p->parent = t;
        q->parent = t;
		t->left = p;
		t->right = q;
        t->isUsed = false;
		r = t;
		size++;
        p = q->next;
        if (p != NULL)
        {
            q = p->next;
        }
        else
        {
            q = NULL;
        }
    }
}

int NodeTree::modify(vector<vector<Node*>>& TreeNodes)
{
    int res = root->value - root->height;
    int r = root->row;
    int c = root->col;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
    
    // refresh cur
    Node* cur = TreeNodes[r][c];
    Node* par = cur->parent;
	int v = cur->value;
    cur->isUsed = true;
    while (par != NULL)
    {
        Node* nei = NULL;
        if (par->left == cur)
        {
            nei = par->right;
        }
        else
        {
            nei = par->left;
        }
        
        if (nei == NULL)
        {
            if (cur->isUsed)
            {
                par->isUsed = true;
            }
            else
            {
                par->row = cur->row;
                par->col = cur->col;
                par->value = cur->value;
                par->height = cur->height;
            }
            cur = par;
            par = cur->parent;
            continue;
        }
        
        if (nei->isUsed && cur->isUsed)
        {
            par->isUsed = true;
        }
        else if (nei->isUsed)
        {
            par->row = cur->row;
            par->col = cur->col;
            par->value = cur->value;
            par->height = cur->height;
        }
        else if (cur->isUsed)
        {
            par->row = nei->row;
            par->col = nei->col;
            par->value = nei->value;
            par->height = nei->height;
        }
        else
        {
            if (nei->value < cur->value)
            {
                par->row = nei->row;
                par->col = nei->col;
                par->value = nei->value;
                par->height = nei->height;
            }
            else
            {
                par->row = cur->row;
                par->col = cur->col;
                par->value = cur->value;
                par->height = cur->height;
            }
        }
        cur = par;
        par = cur->parent;
    }
    
    // refresh others
    for (int i = 0; i < 4; i++)
    {
        int _r = r + dx[i];
        int _c = c + dy[i];
        if (_r <= 0 || _r >= row - 1 || _c <= 0 || _c >= col - 1)
        {
            continue;
        }
        cur = TreeNodes[_r][_c];
        if (TreeNodes[_r][_c]->isUsed)
        {
            continue;
        }
		cur->value = min(cur->value, max(cur->height, v));
        par = cur->parent;
        while (par != NULL)
        {
            Node* nei = NULL;
            if (par->left == cur)
            {
                nei = par->right;
            }
            else
            {
                nei = par->left;
            }

            if (nei == NULL)
            {
                if (cur->isUsed)
                {
                    par->isUsed = true;
                }
                else
                {
                    par->row = cur->row;
                    par->col = cur->col;
                    par->value = cur->value;
                    par->height = cur->height;
                }
                cur = par;
                par = cur->parent;
                continue;
            }

            if (nei->isUsed && cur->isUsed)
            {
                par->isUsed = true;
            }
            else if (nei->isUsed)
            {
                par->row = cur->row;
                par->col = cur->col;
                par->value = cur->value;
                par->height = cur->height;
            }
            else if (cur->isUsed)
            {
                par->row = nei->row;
                par->col = nei->col;
                par->value = nei->value;
                par->height = nei->height;
            }
            else
            {
                if (nei->value < cur->value)
                {
                    par->row = nei->row;
                    par->col = nei->col;
                    par->value = nei->value;
                    par->height = nei->height;
                }
                else
                {
                    par->row = cur->row;
                    par->col = cur->col;
                    par->value = cur->value;
                    par->height = cur->height;
                }
            }
            cur = par;
            par = cur->parent;
        }  
    }
    return res;
}

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
        int row = heightMap.size();
        if (row <= 2)
        {
            return 0;
        }
        int col = heightMap[0].size();
        if (col <= 2)
        {
            return 0;
        }
        NodeTree* t = new NodeTree(row, col);
        Node* q = NULL;
        vector<vector<Node*>> TreeNodes(row, vector<Node*>(col, NULL));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Node* p = new Node();
                p->height = heightMap[i][j];
                p->row = i;
                p->col = j;
                if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                {
                    p->value = heightMap[i][j];
                }
                else
                {
                    p->value = INT_MAX;
                }
                if (q != NULL)
                {
                    q->next = p;
                }
                p->next = NULL;
                p->isUsed = false;
                p->parent = NULL;
				p->left = NULL;
				p->right = NULL;
				q = p;
				TreeNodes[i][j] = p;
            }
        }
        t->initialize(TreeNodes[0][0]);
        int sum = 0;
		for (int i = 0; i < row * col; i++)
        {
            sum += t->modify(TreeNodes);
        }
		return sum;
	}
};
