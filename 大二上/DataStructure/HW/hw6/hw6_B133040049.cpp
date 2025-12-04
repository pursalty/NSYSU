// Author: B133040049 李梓銜
// Date: 2025/11/5
// Purpose:  給予一串數字，找出所有出現次數為奇數之數字
//           -> 利用 Binary Search Tree 來解決此問題
//           檢查每一個數字:
//           1. 若找到相等者，表示之前已經出現過奇數次，則刪除該node
//           2. 若未找到相等者，表示之前出現過偶數次（含零次），則將該數字插入

#include <bits/stdc++.h>
using namespace std;

// 建立一個struct來表示tree的各個節點
struct Node
{
    // 宣告key, left, right來儲存節點值、左子樹、右子樹
    int key;
    Node *left;
    Node *right;
    // 宣告一個condstructor來初始化
    Node(int value)
    {
        key = value;
        right = nullptr;
        left = nullptr;
    }
};

// 建立一個class來進行Binary Search Tree
class BST
{
protected:
    // 指向根結點
    Node *top;

public:
    // constructor, 初始空樹
    BST() : top(nullptr) {}

    // 取得root
    Node *root() const { return top; }

    // 建立新節點
    Node *newNode(int key)
    {
        Node *node = new Node(key);
        return node;
    }

    // 用來尋找此key在不在tree中
    bool findNode(Node *root, int key)
    {
        // tree為empty tree或找到底部仍沒找到->return faslse
        if (root == nullptr)
            return false;

        // 找到了->return true
        else if (root->key == key)
            return true;

        // root的key比key大->去left subtree找
        else if (root->key > key)
            return findNode(root->left, key);

        // 去right subtree找
        return findNode(root->right, key);
    }

    // 用來找right subtree最左邊的底部元素，也就是最right subtree最左邊最小元素
    Node *findMinNode(Node *root)
    {
        // 若tree為空->return nullptr
        if (root == nullptr)
            return nullptr;
        // 尋找minimum node
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    // 用來插入節點
    Node *insertNode(Node *root, int key)
    {
        // 若tree為空或已走到正確位置，則直接新增
        if (root == nullptr)
        {
            return newNode(key);
        }
        // 依照規定將key插入到tree中
        else
        {
            // 若key < root->key 向左走
            if (key < root->key)
            {
                root->left = insertNode(root->left, key);
            }
            // 若key > root->key 向右走
            else if (key > root->key)
            {
                root->right = insertNode(root->right, key);
            }
        }
        return root;
    }

    // 用來刪除節點
    Node *deleteNode(Node *root, int key)
    {
        // 若為空或已完成->直接回傳
        if (root == nullptr)
            return root;

        // 若root->key > key往左走
        if (root->key > key)
            root->left = deleteNode(root->left, key);

        // 若root->key < key往右走
        else if (root->key < key)
            root->right = deleteNode(root->right, key);

        else
        {
            // 若只有一個son->直接刪除並往上連接
            if (root->left == nullptr)
            {
                Node *tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->right == nullptr)
            {
                Node *tmp = root->left;
                delete root;
                return tmp;
            }

            // 若有兩個son，則依規定執行
            else
            {
                // 先找到right subtree最小的元素
                Node *tmp = findMinNode(root->right);
                // 代替掉欲刪除元素
                root->key = tmp->key;
                // 再將原本位置的right subtree最小的元素刪除
                root->right = deleteNode(root->right, tmp->key);
            }
        }
        return root;
    }

    // 用來將tree遍歷一遍，並將各個元素儲存到一個vector<pair<int, pair<int, int>>>裡面
    void collect(Node *root, vector<pair<int, pair<int, int>>> &res)
    {
        // 若為empty tree則不需執行任何動作
        if (root == nullptr)
            return;

        // 宣告leftVal, rightVal來記錄左、右子節點的值
        int leftVal = (root->left == nullptr ? 0 : root->left->key);
        int rightVal = (root->right == nullptr ? 0 : root->right->key);

        // 將資料push進入vector中
        res.push_back(make_pair(root->key, make_pair(leftVal, rightVal)));

        // 先將left subtree走完紀錄完，再紀錄right subtree
        collect(root->left, res);
        collect(root->right, res);
    }

    // 宣告下列function用來在main function中可以呼叫插入，刪除和尋找key的函式
    void insert(int key) { top = insertNode(top, key); }
    void erase(int key) { top = deleteNode(top, key); }
    bool contain(int key) { return findNode(top, key); }

    // 用來將tree輸出成規定格式
    void outputTree(const vector<pair<int, pair<int, int>>> &res)
    {
        cout << "node: ";
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i].first << " ";
        }
        cout << endl;

        cout << "left: ";
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[j].second.first << " ";
        }
        cout << endl;

        cout << "right: ";
        for (int k = 0; k < res.size(); k++)
        {
            cout << res[k].second.second << " ";
        }
        cout << endl
             << endl;
    }
};

// 用來將tree資料從小到大排序
bool cmp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    return a.first < b.first;
}

int main()
{
    // 用來可以重複執行多筆測資，直到按Ctrl+C來結束
    while (true)
    {
        // 宣告一個tree的BST
        BST tree;

        // 用來輸入測資
        int n;

        // 用來儲存tree資料
        vector<pair<int, pair<int, int>>> info;

        // 用來輸入資料，並執行要求動作
        while (cin >> n && n != -1)
        {
            // 若輸入的資料已經存在於tree中，代表數量奇數+1 = 偶數->刪除資料
            if (tree.contain(n))
                tree.erase(n);

            // 若非則插入
            else
                tree.insert(n);
        }

        // 如果剛剛是因為 EOF 才跳出（而不是讀到 -1），就整個結束
        if (!cin)
            break;

        // 呼叫function來蒐集欲輸出資料
        tree.collect(tree.root(), info);
        // 將輸出資料從小到大排列
        sort(info.begin(), info.end(), cmp);
        // 輸出資料
        tree.outputTree(info);
    }
    return 0;
}

/*test data:

10 7 12 8 11 4 -1
3 3 5 9 5 3 4 8 5 3 10 10 8 -1
2 1 3 2 -1

*/