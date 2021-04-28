# BFS算法框架(宽度优先搜索)

## 1 BFS框架

1.　BFS一般都是用队列实现　　
2.　找到的路径一定是最短的　但是空间复杂度高
3.　实际上就是从一副＂图＂中找到起点和目标的最小距离

```c++
//求从起点到终点之间的距离
int BFS(Node start, Node targrt)
{
    queue <int> q; //使用队列解决问题
    set <Node> visited; //避免走回头路
    
    //定义一下初始的东西
    q.push(start);
    visited.insert(start);
    int step = 0; //记录扩散的步数
    
    while(q 不是空)
    {
        int sz = q.size();
        for(int i = 0; i < sz; i++)
        {
            //拿第一个
            Node cur = q.front();
            //判断是不是终点！！！
            if(cur 是终点) return step;
            
            //不是终点就把相邻的节点加到队列中 visited同时加入
            for(Node x : cur的相邻节点)
            {
                q.push(x);
                visited.insert(x);
            }
        }
        step++;
    }
    
}
```

# 2 例子

## 2.1 二叉树的最小高度

[分析]　终点就是左右子树都是空的　不然就把左右子树加到队列里去

```c++
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> my_queue;
        my_queue.push(root);

        int res = 1;
        while(!my_queue.empty())
        {
            int size = my_queue.size();
            for(int i = 0; i < size; i++)
            {
                //拿第一个
                TreeNode *node = my_queue.front();
                my_queue.pop();
                
                //判断是不是终点！！！
                if(node->left == nullptr && node->right == nullptr) return res;
                
                //不是终点就把相邻的节点加到队列中
                if(node->left) my_queue.push(node->left);
                if(node->right) my_queue.push(node->right);
            }
            res++;
        }
        return res;
    }
};
```

## 2.2 解开密码锁的最少次数

你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

```c++
class Solution {
public:

    string plusOne(string s, int j)
    {
        if (s[j] == '9') s[j] = '0';
        else s[j] = s[j] + 1;
        return s;
    }
    string minusOne(string s, int j)
    {
        if (s[j] == '0') s[j] = '9';
        else s[j] = s[j] - 1;
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        
        map<string, int> deads;
        for(string s:deadends)  deads[s]++;
        
        queue<string> my_queue;
        set<string> visited;

        int step = 0;
        my_queue.push("0000");
        visited.insert("0000");

        while(!my_queue.empty())
        {
            int size = my_queue.size();
            for(int i = 0; i < size; i++)
            {
                string cur = my_queue.front();
                my_queue.pop();
                
                //达到目标
                if(cur == target) return step;
                if(deads.count(cur)) continue;

                //不然就每一位拨一下
                for(int j = 0; j < 4; j++)
                {
                    string up = plusOne(cur, j);
                    if(count(visited.begin(),visited.end(), up) == 0) 
                    {
                        my_queue.push(up);
                        visited.insert(up);
                    } 
                    string down = minusOne(cur,j);
                    if(count(visited.begin(),visited.end(), down) == 0)
                    {
                        my_queue.push(down);
                        visited.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```


